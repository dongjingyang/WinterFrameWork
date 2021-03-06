
#ifndef DComBase_h__
#define DComBase_h__

#include "IDComBase.h"
namespace dscom 
{
#define DS_DEFINE_IID(iface, uuid_string)	struct __declspec(uuid(uuid_string)) iface

	//////////////////////////////////////////////////////////////////////////
	// ROT:
	//全局对象，随着需要创建
	DS_DEFINE_IID(IDsRunningObjectTable, "{DF32DCC9-D4AB-4FE1-8252-803C56FF6315}");


	interface IDsRunningObjectTable : public IDComBase
	{
	public:
		STDMETHOD(Register)(const GUID& rpid, IDComBase *punk) = 0;
		STDMETHOD(Revoke)(const GUID& rpid) = 0;
		STDMETHOD(IsRunning)(const GUID& rpid) = 0;
		STDMETHOD(GetObject)(const GUID& rpid, IDComBase **ppunk) = 0;
		STDMETHOD(RevokeAll)() = 0;
	};



	//特殊类工厂
	interface IDSClassFactory: public IClassFactory
	{
	public:
		STDMETHOD(CreateInstance)(IDComBase *prot, IDComBase *punkOuter, const IID& riid, void **ppvObject) PURE;
		STDMETHOD_(CLSID, GetAt)(LONG nIndex) PURE;
		STDMETHOD_(LONG, GetCount)() PURE;
		STDMETHOD_(LPCTSTR, ProgIDFromCLSID)(REFCLSID clsid) PURE;

	};
	DS_DEFINE_IID(IDSClassFactory,"{6966E385-DBFA-4131-A29E-D0E9464F3F53}");

	// {E2247B54-E329-4ca8-8361-6499FDFF98F4}
	DC_DEFINE_GUID(CLSID_CDCClassFactory, 
		0xe2247b54, 0xe329, 0x4ca8, 0x83, 0x61, 0x64, 0x99, 0xfd, 0xff, 0x98, 0xf4);
}//namespace dscom
#endif // DComBase_h__
