#include "DcomRotPackeage.h"
#include "basic.h"
#include "WinterException.h"


namespace Winter
{
	CDcomRotPackeage::CDcomRotPackeage(CRunningObjTable *pWinterRot) :m_Rot(pWinterRot)
	{

	}


	CDcomRotPackeage::~CDcomRotPackeage()
	{
	}

	STDMETHODIMP CDcomRotPackeage::Register(const GUID& rpid, IDComBase *punk)
	{
		return E_NOTIMPL;
		INVALIDARGRETURN(punk);
		WCHAR *pBuf = new WCHAR[MAX_GUID];
		memset(pBuf, NULL, MAX_GUID*sizeof(TCHAR));
		::StringFromGUID2(rpid, pBuf, MAX_GUID);
		INVALIDARGRETURN(pBuf);
		
		//m_Rot->Regesiter(pBuf, );
		return E_NOTIMPL;
	}

	STDMETHODIMP CDcomRotPackeage::Revoke(const GUID& rpid)
	{
		return S_OK;
	}

	STDMETHODIMP CDcomRotPackeage::IsRunning(const GUID& rpid)
	{
		return S_OK;
	}

	STDMETHODIMP CDcomRotPackeage::GetObject(const CLSID& clsid, const GUID& rpid, IDComBase **ppunk)
	{
		DS_String pClsidBuf;
		::StringFromGUID2(clsid, (LPOLESTR)pClsidBuf.c_str(), MAX_GUID);
		INVALIDARGRETURN(!pClsidBuf.empty());

		DS_String pIidBuf;
		::StringFromGUID2(clsid, (LPOLESTR)pIidBuf.c_str(), MAX_GUID);
		INVALIDARGRETURN(!pIidBuf.empty());
		m_Rot->GetObject(pClsidBuf.c_str(), pIidBuf.c_str(), (void**)ppunk);
		return S_OK;
	}

	STDMETHODIMP CDcomRotPackeage::RevokeAll()
	{
		return S_OK;
	}

}
