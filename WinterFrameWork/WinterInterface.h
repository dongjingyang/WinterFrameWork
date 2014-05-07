#ifndef WinterInterface_h__
#define WinterInterface_h__

MIDL_INTERFACE("{F5659CCB-88B1-42fd-A998-E9A0923F120B}")
IWinterEnv:public IUnknown
{
	STDMETHOD(InitEnv)(LPCTSTR lpszCfg) PURE;
	STDMETHOD(GetObject)(const CLSID& clsid, const GUID& rpid, void **ppunk) PURE;
};

// {4FC64B25-C618-4F3B-B4D7-7523DDEA9358}
static const GUID CLSID_WinterEnv =
{ 0x4fc64b25, 0xc618, 0x4f3b, { 0xb4, 0xd7, 0x75, 0x23, 0xdd, 0xea, 0x93, 0x58 } };

#endif // WinterInterface_h__



