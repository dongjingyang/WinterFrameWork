#include "gtest/gtest.h"
#include "..\WinterFrameWork\XmlMine.h"

using namespace  Winter;

class CXmlMineTest:public testing::Test
{
public:
	CXmlMine     *XmlMine;
private:
protected:
	virtual void  SetUp()
	{
		XmlMine = new CXmlMine(_T("D:\\develop\\myproject\\WinterFrameWork\\WinterFrameWork\\Debug\\config.xml"));
	}
	virtual void TearDown()
	{
		delete XmlMine;
	}
};

TEST_F(CXmlMineTest,testXmlMine)
{

	ASSERT_NE(XmlMine->GetLibraryCount(),0);
	EXPECT_EQ(XmlMine->GetLibraryCount(), 4);
	DS_LIBRARYVEC   *vecTemp = XmlMine->GetVecLibrary();
	ASSERT_NE(vecTemp->size(),0);
	EXPECT_EQ(vecTemp->size(), 4);
}
TEST_F(CXmlMineTest, testListLibrary)
{
	DS_LIBRARYVEC   *vecTemp = XmlMine->GetVecLibrary();
	ASSERT_NE(vecTemp->size(), 0);
	EXPECT_EQ(vecTemp->size(), 4);

	for (size_t i = 0; i < vecTemp->size(); i++)
	{
		EXPECT_EQ((*vecTemp)[i]->tName, _T("SmallCompoent.dll"));
	}
}