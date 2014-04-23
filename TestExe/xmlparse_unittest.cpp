// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gtest/gtest.h"
#include <Windows.h>
#include "..\WinterFrameWork\XMLResource.h"
#include <time.h>
using namespace Winter;


class XMLTest : public testing::Test 
{
protected:
	// Remember that SetUp() is run immediately before a test starts.
	// This is a good place to record the start time.
	virtual void SetUp() 
	{
		start_time_ = time(NULL);
	}

	// TearDown() is invoked immediately after a test finishes.  Here we
	// check if the test was too slow.
	virtual void TearDown()
	{
		// Gets the time when the test finishes
		const time_t end_time = time(NULL);

		// Asserts that the test took no more than ~5 seconds.  Did you
		// know that you can use assertions in SetUp() and TearDown() as
		// well?
		EXPECT_TRUE(end_time - start_time_ <= 5) << "The test took too long.";
	}

	// The UTC time (in seconds) when the test starts
	time_t start_time_;
};


class XMLTestFirst : public XMLTest
{
protected:
	virtual void SetUp()
	{
		XMLTest::SetUp();
		xmlResource = new XMLResource(_T("D:\\develop\\myproject\\WinterFrameWork\\WinterFrameWork\\Debug\\WinterDemo.xml"));
	}


	 virtual void TearDown() 
	 {
	   XMLTest::TearDown();
	   delete xmlResource;
	 }

	 XMLResource *xmlResource;
};

TEST_F(XMLTestFirst,READLIBRARY)
{	
	const vector<TLibrary*> *pLibs = xmlResource->getLibraries();
	for(int i=0; i<pLibs->size(); i++)
	{
		
		TLibrary* plib = (TLibrary*)(*pLibs)[i];
		EXPECT_EQ(_T("../lib/injectBeanImpl.dll"),plib->Path);
		EXPECT_EQ(_T("injectBeanImpl"),plib->Name);
	}
	EXPECT_EQ(1,pLibs->size());
}

TEST_F(XMLTestFirst,READBEANS)
{
	const vector<TLibrary*> *pLibs = xmlResource->getLibraries();
	for(int i=0; i<pLibs->size(); i++)
	{
		TLibrary* plib = (TLibrary*)(*pLibs)[i];

		const vector<TBean>pBean = plib->Beans;
		EXPECT_EQ(1,pBean.size());
		for (int i =0 ; i < pBean.size();i++)
		{
			TBean tempBean = (TBean)pBean[i];
			EXPECT_EQ(_T("TheAction"),tempBean.Name);
			EXPECT_EQ(_T("LowerAction"),tempBean.ClassName);
			EXPECT_EQ(true,tempBean.Singleton);
 		}
		 
		
	}
}