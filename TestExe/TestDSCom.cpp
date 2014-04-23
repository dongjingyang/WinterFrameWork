#include "gtest/gtest.h"
#include <objbase.h>
#include <tchar.h>
#include "SmallCompoent/DComBase.h"
#include "SmallCompoent/SmallCompoent.h"
using namespace dscom;

class TestDSCom:public testing::Test
{
public:
protected:
	virtual void SetUp()
	{
		CoInitialize(NULL);
		HINSTANCE   hInst = LoadLibrary(_T("SmallCompoent.dll"));
		ASSERT_NE((LONG)hInst,NULL);
		typedef HRESULT   (__stdcall *pfnGetObjectFunc )(REFCLSID,REFIID,void**);
		pfnGetObjectFunc pfnFunc = NULL;
		pfnFunc = (pfnGetObjectFunc)GetProcAddress(hInst,"DllGetClassObject");

		ASSERT_NE((LONG)pfnFunc,NULL);
		
		IDSClassFactory* pfc = NULL;
		pfnFunc(CLSID_SmallCompoent,__uuidof(IDSClassFactory),(void**)&pfc);
		ASSERT_NE((LONG)pfc,NULL);
		LONG lCount = pfc->GetCount();
		pfc->GetAt(0);

		pfc->CreateInstance(NULL,NULL,__uuidof(ITestDsCom),(void**)&testDsCom);
	}
	virtual void TearDown()
	{
		CoUninitialize();
	}
protected:
			UTIL::com_ptr<ITestDsCom>  testDsCom;
};


TEST_F(TestDSCom,TestDllLoad)
{
	testDsCom->SayHelloWorld(_T("HAHAHAHAHA"));
	return;
}