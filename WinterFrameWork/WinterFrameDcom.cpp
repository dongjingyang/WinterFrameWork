#include "WinterFrameDcom.h"
#include "XmlMine.h"
#include "AssemblyPlant.h"
#include "basic.h"
#include "WinterException.h"
#include "string.h"

using namespace  Winter;
CWinterFrameDcom::CWinterFrameDcom()
{
}


CWinterFrameDcom::~CWinterFrameDcom()
{
}

STDMETHODIMP CWinterFrameDcom::InitEnv(LPCTSTR lpszCfg)
{
	CAssemblyPlant  *CAssembly = new CAssemblyPlant(new CXmlMine(lpszCfg));
	return S_OK;
}


STDMETHODIMP CWinterFrameDcom::GetObject(const CLSID& clsid, const GUID& rpid, void **ppunk)
{
	HRESULT   hr = E_FAIL;

	shared_ptr<TCHAR> spClsid(new TCHAR[MAX_GUID]);
	shared_ptr<TCHAR> spGuid(new TCHAR[MAX_GUID]);


	::StringFromGUID2(clsid, (LPOLESTR)spClsid.get(), MAX_GUID);
	INVALIDARGRETURN(_tcslen(spClsid.get()));
	ver(spClsid.get());

	::StringFromGUID2(rpid, (LPOLESTR)spGuid.get(), MAX_GUID);
	INVALIDARGRETURN(_tcslen(spGuid.get()));
	ver(spGuid.get());

	CRunningObjTable::Instance().GetObject(spClsid.get(), spGuid.get(), ppunk);
	return S_OK;
}
