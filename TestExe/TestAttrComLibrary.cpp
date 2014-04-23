#include "gtest/gtest.h"
#include <objbase.h>
#include <atlcomcli.h>
#import "SimpleAttrCom/SimpleAttrCom.tlb"  no_namespace


class CTestAttrCom:public testing::Test
{
public:
protected:
	virtual void SetUp() 
	{
		CoInitialize(NULL);

		typedef HRESULT (__stdcall * pfnFunc)(REFCLSID,REFIID,void**);
		pfnFunc fnGetClassObj = NULL;
		HINSTANCE hdllInst = LoadLibrary(_T("SimpleAttrCom.dll"));
		if (NULL == hdllInst)
		{
			EXPECT_NE((long)hdllInst,NULL);
		}
		fnGetClassObj = (pfnFunc)GetProcAddress(hdllInst,"DllGetClassObject");
		EXPECT_NE((long)fnGetClassObj,NULL);
		IClassFactory  * pcf = NULL;
		CLSID   clsid;
		IIDFromString(_T("{4ED3625F-9551-4cc0-81DA-864418A01D2D}"),&clsid);
		//HRESULT hr = CoCreateInstance(clsid,NULL,NULL,__uuidof(ISimpleAttrCom),(void**)&spSimpleAttrCom);
		//spSimpleAttrCom->(clsid);
		HRESULT hr = (fnGetClassObj)(clsid,IID_IClassFactory,(void**)&pcf);
		EXPECT_EQ(hr,S_OK);
		EXPECT_NE((long)pcf,NULL);
		IID     actionIid;
		hr  = IIDFromString(_T("{2C2CD1DC-4B13-431e-B4CF-B0BABF76BFA7}"),&actionIid);
		EXPECT_EQ(hr,S_OK);

		hr = pcf->CreateInstance(NULL,actionIid,(void**)&spSimpleAttrCom);
		EXPECT_EQ(hr,S_OK);
	}
	virtual void TearDown()
	{
		CoUninitialize();
	}
public:
	CComPtr<ISimpleAttrCom> spSimpleAttrCom;
private:
};

TEST_F(CTestAttrCom,TestAttrComLoad)
{
	spSimpleAttrCom->TestAdd();
}