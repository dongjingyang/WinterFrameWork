#include "gtest/gtest.h"
#include <objbase.h>
#include "TestComLibrary/TestComLibrary_i.h"
#include "TestComLibrary/TestComLibrary_i.c"
#include <tchar.h>
#include <atlcomcli.h>


class CcomTest:public testing::Test
{
protected:
	virtual void SetUp() 
	{
		CoInitialize(NULL);

		typedef HRESULT (__stdcall * pfnFunc)(REFCLSID,REFIID,void**);
		pfnFunc fnGetClassObj = NULL;
		HINSTANCE hdllInst = LoadLibrary(_T("TestComLibrary.dll"));
		if (NULL == hdllInst)
		{
			EXPECT_NE((long)hdllInst,NULL);
		}
		fnGetClassObj = (pfnFunc)GetProcAddress(hdllInst,"DllGetClassObject");
		EXPECT_NE((long)fnGetClassObj,NULL);
		IClassFactory  * pcf = NULL;
		CLSID   clsid;
		IIDFromString(_T("{400DB0F9-BB41-4ACD-A4EB-2219019F4F28}"),&clsid);
		HRESULT hr = (fnGetClassObj)(clsid,IID_IClassFactory,(void**)&pcf);
		EXPECT_EQ(hr,S_OK);
		EXPECT_NE((long)pcf,NULL);
		IID     actionIid;
		hr  = IIDFromString(_T("{543370AB-CA7B-4D43-A3F5-55B15CCF7BA2}"),&actionIid);
		EXPECT_EQ(hr,S_OK);

		hr = pcf->CreateInstance(NULL,actionIid,(void**)&spTestAction);
		EXPECT_EQ(hr,S_OK);
	}

	virtual  void TearDown()
	{
		CoUninitialize();
	}
public:
	CComPtr<ITestAction> spTestAction;
};


TEST_F(CcomTest,TestLoadLibbrary)
{
	if (NULL == spTestAction)
	{
		testing::AssertionFailure()<<"sptestaction is null";
	}
	spTestAction->TestAdd(1,2);
}