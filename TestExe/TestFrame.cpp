#include "gtest/gtest.h"
#include <objbase.h>
#include <tchar.h>
#include "../WinterFrameWork/WinterInterface.h"
#include "../Dcom/DComBase.h"
#include "../Dcom/DComUtility.h"
#include "SmallCompoent/SmallCompoent.h"
using namespace dscom;

class CFrameTest :public testing::Test
{
protected:
	virtual void  SetUp()
	{
		HINSTANCE   hInst = LoadLibrary(_T("WinterFrameWork_d.dll"));
		ASSERT_NE((LONG)hInst, NULL);
		typedef HRESULT(__stdcall *pfnGetObjectFunc)(REFCLSID, REFIID, void**);
		pfnGetObjectFunc pfnFunc = NULL;
		pfnFunc = (pfnGetObjectFunc)GetProcAddress(hInst, "DllGetClassObject");

		ASSERT_NE((LONG)pfnFunc, NULL);

		IDSClassFactory* pfc = NULL;
		pfnFunc(CLSID_WinterEnv, __uuidof(IDSClassFactory), (void**)&pfc);
		ASSERT_NE((LONG)pfc, NULL);
		LONG lCount = pfc->GetCount();
		pfc->GetAt(0);

		pfc->CreateInstance(NULL, NULL, __uuidof(IWinterEnv), (void**)&testDsCom);
		testDsCom->InitEnv(_T("config.xml"));
		testDsCom->GetObject(CLSID_SmallCompoent, __uuidof(ITestDsCom),(void**)&testDsComObj);

	}
	virtual void TearDown()
	{
		
	}
public:
	UTIL::com_ptr<IWinterEnv>  testDsCom;
	UTIL::com_ptr<ITestDsCom>  testDsComObj;
};

TEST_F(CFrameTest, TestDllLoad)
{
	testDsCom->InitEnv(_T("config.xml"));
	return;
}

TEST_F(CFrameTest, TestGetObject)
{
	testDsComObj->SayHelloWorld(_T("HAHAHAHAHA"));
	return;
}