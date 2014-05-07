#pragma once
#include "dscom_all.h"
#include "WinterInterface.h"



using namespace dscom;
class CWinterFrameDcom :public IWinterEnv,
	public CDSClassImpl<CWinterFrameDcom>,
	public CUnknownImp
{
public:
	CWinterFrameDcom();
	~CWinterFrameDcom();
	UNKNOWN_IMP1(IWinterEnv);
	virtual STDMETHODIMP InitEnv(LPCTSTR lpszCfg);

	virtual STDMETHODIMP GetObject(const CLSID& clsid, const GUID& rpid, void **ppunk);

};

