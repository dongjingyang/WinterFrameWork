#include "Bean_dcomImpl.h"
#include "Bean.h"
#include "LibraryTemplate.h"
#include <objbase.h>
#include "..\include\basic.h"
#include "WinterException.h"
#include "..\Dcom\DComBase.h"
#include "..\Dcom\DCom.h"
#include "..\Dcom\DComClassImpl.h"
#include "DcomRotPackeage.h"

using namespace dscom;
namespace Winter
{

	CBean_dcomImpl::CBean_dcomImpl(TBean * pBeanMateri) :m_pBeanMateri(pBeanMateri)
	{
		FAILEDNORETURN(pBeanMateri);
	}


	CBean_dcomImpl::~CBean_dcomImpl()
	{
	}

	HRESULT CBean_dcomImpl::GetBean(LPCTSTR lpcsObjId, void ** pOuter)
	{
		INVALIDARGRETURN(lpcsObjId);
		if (m_Obj)
		{
			*pOuter = m_Obj;
			return S_OK;
		}
		HRESULT hr = E_FAIL;
		HINSTANCE   hInst = LoadLibrary(_T("SmallCompoent.dll"));
		HRTHREOWEX(hInst,NonInstance, "load library is faild", E_INVALIDARG);
		typedef HRESULT(__stdcall *pfnGetObjectFunc)(REFCLSID, REFIID, void**);
		pfnGetObjectFunc pfnFunc = NULL;
		pfnFunc = (pfnGetObjectFunc)GetProcAddress(hInst, "DllGetClassObject");
		HRTHREOWEX(pfnFunc,NonValue, "pfnFunc is Null,the dll is invalid", E_POINTER);
		CLSID   clsid;
		IIDFromString(m_pBeanMateri->tCLsid.c_str(), &clsid);
		IID     actionIid;
		hr = IIDFromString(lpcsObjId, &actionIid);
		IDSClassFactory* pfc = NULL;
		pfnFunc(clsid, __uuidof(IDSClassFactory), (void**)&pfc);
		HRTHREOWEX(pfc,NonValue, "IDSClassFactory is Null, the dll is not dscom dll", E_NOINTERFACE);
		pfc->CreateInstance(NULL, &CDcomRotPackeage::Instance(), actionIid, (void**)&m_Obj);
		HRTHREOWEX(m_Obj, NonValue, "pOuter is Null,the interface is not found", E_NOINTERFACE);
		*pOuter = m_Obj;
		return S_OK;
	}

}
