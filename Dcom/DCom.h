#ifndef DCom_h__
#define DCom_h__
#include "DComUtility.h"

#include <tchar.h>
#include <objbase.h>
#include "DComBase.h"

namespace dscom 
{

	class CUnknownImp
	{
	public:
		ULONG m_RefCount;
		CUnknownImp(): m_RefCount(0) {}
		virtual ~CUnknownImp(){}
	};

	class IDComBase_Nondelegate
	{
	public:
		STDMETHOD(QueryInterface_Nondelegate)(REFGUID riid, void **ppv) = 0;
		STDMETHOD_(ULONG, AddRef_Nondelegate)() = 0;
		STDMETHOD_(ULONG, Release_Nondelegate)() = 0;
	};


#define MAX_PROGIDLEN	100



	
#define QIBEGIN	\
	STDMETHOD(QueryInterface)(REFGUID riid, void **ppv) {

#define QIUNKNOWN	\
	if(de_uuidof(IDComBase) == riid) { *ppv = static_cast<IDComBase*>(this); AddRef(); return S_OK; }

#define QIUNKNOWN_(icast)	\
	if(de_uuidof(IDComBase) == riid) { *ppv = static_cast<IDComBase*>(static_cast<icast*>(this)); AddRef(); return S_OK; }

#define QIENTRY(iface)	\
	if(de_uuidof(iface) == riid) { *ppv = static_cast<iface*>(this); AddRef(); return S_OK; }

#define QIENTRY_(iface, icast)	\
	if(de_uuidof(iface) == riid) { *ppv = static_cast<iface*>(static_cast<icast*>(this)); AddRef(); return S_OK; }

#define QIEND \
	return E_NOINTERFACE; }

	// 我要看对象计数
#ifdef _DEBUG_INTERLOCKED_VIEW
	class CInterlockedView_
	{
	public:
		ULONG& m_RefCount;
		void* m_this;
		CInterlockedView_(void* pthis, ULONG& RefCount):m_this(pthis),m_RefCount(RefCount)
		{
			TCHAR out[64] = {0};
			wsprintf(out, "Enter %x = %d ------> ", m_this, m_RefCount);
			Msg(out);
		}
		~CInterlockedView_()
		{
			TCHAR out[64] = {0};
			wsprintf(out, "Leave %x = %d\n", m_this, m_RefCount);
			Msg(out);
		}
	};
#define ADDREF	\
	STDMETHOD_(ULONG, AddRef)()	\
	{ CInterlockedView_ v(this, m_RefCount); return InterlockedIncrement((LONG*)(LPVOID)&m_RefCount); }

#define RELEASE	\
	STDMETHOD_(ULONG, Release)()	\
	{ CInterlockedView_ v(this, m_RefCount); if(InterlockedDecrement((LONG*)(LPVOID)&m_RefCount)) return m_RefCount; delete this; return 0; }

#else

#define UNKNOWN_IMP_SPEC(entrys) \
	QIBEGIN  QIUNKNOWN  entrys  QIEND  ADDREF  RELEASE

#define UNKNOWN_IMP_SPEC_(icast, entrys) \
	QIBEGIN  QIUNKNOWN_(icast)  entrys  QIEND  ADDREF  RELEASE

#define ADDREF	\
	STDMETHOD_(ULONG, AddRef)()	\
	{ return InterlockedIncrement((LONG*)(LPVOID)&m_RefCount); }

#define RELEASE	\
	STDMETHOD_(ULONG, Release)()	\
	{ if(InterlockedDecrement((LONG*)(LPVOID)&m_RefCount)) return m_RefCount; delete this; return 0; }

#endif

#define UNKNOWN_IMP1(i) \
	UNKNOWN_IMP_SPEC( QIENTRY(i) )
#define UNKNOWN_IMP2(i1, i2) \
	UNKNOWN_IMP_SPEC( QIENTRY(i1) QIENTRY(i2) )
#define UNKNOWN_IMP3(i1, i2, i3) \
	UNKNOWN_IMP_SPEC( QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) )
#define UNKNOWN_IMP4(i1, i2, i3, i4) \
	UNKNOWN_IMP_SPEC( QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) )
#define UNKNOWN_IMP5(i1, i2, i3, i4, i5) \
	UNKNOWN_IMP_SPEC( QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) QIENTRY(i5) )
#define UNKNOWN_IMP6(i1, i2, i3, i4, i5, i6) \
	UNKNOWN_IMP_SPEC( QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) QIENTRY(i5) QIENTRY(i6) )
#define UNKNOWN_IMP7(i1, i2, i3, i4, i5, i6, i7) \
	UNKNOWN_IMP_SPEC( QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) QIENTRY(i5) QIENTRY(i6) QIENTRY(i7) )
#define UNKNOWN_IMP8(i1, i2, i3, i4, i5, i6, i7, i8) \
	UNKNOWN_IMP_SPEC( QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) QIENTRY(i5) QIENTRY(i6) QIENTRY(i7) QIENTRY(i8) )
#define UNKNOWN_IMP9(i1, i2, i3, i4, i5, i6, i7, i8, i9) \
	UNKNOWN_IMP_SPEC( QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) QIENTRY(i5) QIENTRY(i6) QIENTRY(i7) QIENTRY(i8) QIENTRY(i9))

#define UNKNOWN_IMP2_(i1, i2) \
	UNKNOWN_IMP_SPEC_(i1, QIENTRY(i1) QIENTRY(i2) )
#define UNKNOWN_IMP3_(i1, i2, i3) \
	UNKNOWN_IMP_SPEC_(i1, QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) )
#define UNKNOWN_IMP4_(i1, i2, i3, i4) \
	UNKNOWN_IMP_SPEC_(i1, QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) )
#define UNKNOWN_IMP5_(i1, i2, i3, i4, i5) \
	UNKNOWN_IMP_SPEC_(i1, QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) QIENTRY(i5) )
#define UNKNOWN_IMP6_(i1, i2, i3, i4, i5, i6) \
	UNKNOWN_IMP_SPEC_(i1, QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) QIENTRY(i5) QIENTRY(i6) )
#define UNKNOWN_IMP7_(i1, i2, i3, i4, i5, i6, i7) \
	UNKNOWN_IMP_SPEC_(i1, QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) QIENTRY(i5) QIENTRY(i6) QIENTRY(i7) )
#define UNKNOWN_IMP8_(i1, i2, i3, i4, i5, i6, i7, i8) \
	UNKNOWN_IMP_SPEC_(i1, QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) QIENTRY(i5) QIENTRY(i6) QIENTRY(i7) QIENTRY(i8) )
#define UNKNOWN_IMP9_(i1, i2, i3, i4, i5, i6, i7, i8, i9) \
	UNKNOWN_IMP_SPEC_(i1, QIENTRY(i1) QIENTRY(i2) QIENTRY(i3) QIENTRY(i4) QIENTRY(i5) QIENTRY(i6) QIENTRY(i7) QIENTRY(i8) QIENTRY(i9))

	//////////////////////////////////////////////////////////////////////////

template<class CLS>
class TStdClsFactory : public IDSClassFactory, private CUnknownImp
{
public: // IDComBase:
	UNKNOWN_IMP2(IDSClassFactory, IClassFactory);

public: // IRSClassFactory:
	STDMETHOD(CreateInstance)(IDComBase *prot, IDComBase *punkOuter, const IID& riid, void **ppv)
	{
		return create_instance(prot, punkOuter, riid, ppv);
	}

	STDMETHOD(LockServer)(BOOL fLock)
	{
		return lock_server(fLock);
	}

	// std factory invoke:
	STDMETHOD(init_class)(IDComBase* prot, IDComBase* punkOuter)
	{
		return !punkOuter ? S_OK : E_INVALIDARG;
	}

	STDMETHOD(init_class_inner)(IDComBase* punkOuter)
	{
		return !punkOuter ? S_OK : E_INVALIDARG;
	}

	// IRSClassFactory:
	STDMETHOD_(CLSID, GetAt)(LONG nIndex) 
	{
		return g_mapClassObject[nIndex+1].clsid;
	}

	STDMETHOD_(LONG, GetCount)()
	{
		LONG lCount = sizeof(g_mapClassObject)/sizeof(g_mapClassObject[0]);

		return (lCount > 0)?lCount-1:0;
	}


	STDMETHOD_(LPCTSTR, ProgIDFromCLSID)(REFCLSID clsid)
	{
		for(size_t i = 1; i < sizeof(g_mapClassObject)/sizeof(g_mapClassObject[0]); ++i)
		{
			if(clsid == g_mapClassObject[i].clsid)
			{
				return g_mapClassObject[i].ProgID;
			}
		}
		return _T("");
	}

public: 
	// IClassFactory
	STDMETHOD (CreateInstance)( 
		/* [unique][in] */ IDComBase *punkOuter,
		/* [in] */ REFIID riid,
		/* [iid_is][out] */ void **ppv)
	{
		return create_instance(punkOuter, riid, ppv);
	}

public:
	static HRESULT create_instance(IDComBase *prot, IDComBase *punkOuter, const IID& riid, void **ppv)
	{
		*ppv = 0;
		// aggregation validate:
		DASSERT(!punkOuter || de_uuidof(IDComBase) == riid, E_INVALIDARG);
		// create new object/aggregation:
		UTIL::sentry<CLS*> p(new CLS);
		DASSERT(p, E_UNEXPECTED);
		((IDComBase_Nondelegate*)(CLS*)p)->AddRef_Nondelegate(); // nondelegation, protect reference count
		DFAILED(p->init_class(prot, punkOuter));
		HRESULT hr = ((IDComBase_Nondelegate*)(CLS*)p)->QueryInterface_Nondelegate(riid, ppv);
		((IDComBase_Nondelegate*)p.detach())->Release_Nondelegate(); // nondelegation, balance reference count or destroy.
		return hr;
	}

	static HRESULT create_instance(IDComBase *punkOuter, const IID& riid, void **ppv)
	{
		*ppv = 0;
		// aggregation validate:
		DASSERT(!punkOuter || de_uuidof(IDComBase) == riid, E_INVALIDARG);
		// create new object/aggregation:
		UTIL::sentry<CLS*> p(new CLS);
		DASSERT(p, E_UNEXPECTED);
		((IDComBase_Nondelegate*)(CLS*)p)->AddRef_Nondelegate(); // nondelegation, protect reference count
		if(punkOuter)
		{
			//CUnknownImp_Inner* pInner = (CUnknownImp_Inner*)(p);
			//RFAILED(pInner->init_class_inner(punkOuter));
		}
		HRESULT hr = ((IDComBase_Nondelegate*)(CLS*)p)->QueryInterface_Nondelegate(riid, ppv);
		((IDComBase_Nondelegate*)p.detach())->Release_Nondelegate(); // nondelegation, balance reference count or destroy.
		return hr;
	}

	static HRESULT lock_server(BOOL /*fLock*/)
	{
		return S_OK;
	}
	static HRESULT GetClassObject(const IID& riid, void **ppv)
	{
		return TStdClsFactory<TStdClsFactory<CLS> >::create_instance(0, 0, riid, ppv);
	}
};
class CNullObjcetUnkown :public IDComBase, private CUnknownImp
{
public:
	UNKNOWN_IMP1(IDComBase);

	// std factory invoke:
	STDMETHOD(init_class)(IDComBase* /*prot*/, IDComBase* punkOuter)
	{
		return !punkOuter ? S_OK : E_INVALIDARG;
	}

	STDMETHOD(init_class_inner)(IDComBase* punkOuter)
	{
		return !punkOuter ? S_OK : E_INVALIDARG;
	}
};



#define BEGIN_CLIDMAP \
	static const struct{ CLSID clsid; HRESULT (*pfnGetClassObject)(const IID&, void**);TCHAR ProgID[MAX_PROGIDLEN];} g_mapClassObject[] = {

#define CLIDMAPENTRY_BEGIN \
	{CLSID_CDCClassFactory,&TStdClsFactory<CNullObjcetUnkown>::GetClassObject, _T("")},

#define CLIDMAPENTRY(CID,CLASS) \
	{CID, &TStdClsFactory<CLASS >::GetClassObject, _T("")},

#define CLIDMAPENTRY_PROGID(CID,CLASS,PROGID) \
	{CID, &TStdClsFactory<CLASS >::GetClassObject, PROGID},


#define CLIDMAPENTRY_END 

#define END_CLIDMAP };


#define DCOM_API  HRESULT __stdcall 
#define DCOM_EXPORTS extern "C"  /*__declspec(dllexport)*/ DCOM_API

#define DEFINE_ALL_EXPORTFUN \
	DCOM_API DSDllGetClassObject(IN REFCLSID rclsid, IN REFIID riid, OUT LPVOID FAR* ppv);\
	DCOM_API DSDllGetClassObject(IN REFCLSID rclsid, IN REFIID riid, OUT LPVOID FAR* ppv)\
	{\
	for(size_t i = 0; i < sizeof(g_mapClassObject)/sizeof(g_mapClassObject[0]); ++i)\
	{\
	if(rclsid == g_mapClassObject[i].clsid)\
	{\
	return g_mapClassObject[i].pfnGetClassObject(riid, ppv);\
	}\
	}\
	return E_INVALIDARG;\
	}\
	\
	DCOM_API DSDllCanUnloadNow(void)\
	{\
	return FALSE;\
	}\
	\
	DCOM_API DSDllRegisterServer(void)\
	{\
	return S_OK;\
	}\
	DCOM_API DSDllUnregisterServer(void)\
	{\
	return S_OK;\
	}

#define END_CLIDMAP_AND_EXPORTFUN }; \
	DEFINE_ALL_EXPORTFUN;
}//namespace dscom
#endif // DCom_h__
