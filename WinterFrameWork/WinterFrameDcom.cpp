#include "WinterFrameDcom.h"
#include "XmlMine.h"
#include "AssemblyPlant.h"
#include "basic.h"
#include "WinterException.h"

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
	DS_String pClsidBuf;
	::StringFromGUID2(clsid, (LPOLESTR)pClsidBuf.c_str(), MAX_GUID);
	INVALIDARGRETURN(!pClsidBuf.empty());

	DS_String pIidBuf;
	::StringFromGUID2(rpid, (LPOLESTR)pIidBuf.c_str(), MAX_GUID);

	CRunningObjTable::Instance().GetObject(pClsidBuf.c_str(), pIidBuf.c_str(),ppunk);
	return S_OK;
}
