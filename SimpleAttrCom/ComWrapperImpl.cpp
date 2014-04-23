#include "stdafx.h"
#include "ComWrapperImpl.h"

template<class T>
CComWrapperImpl<T>::CComWrapperImpl()
{

}

template<class T>
HRESULT __stdcall CComWrapperImpl<T>::QueryInterface( const IID& iid, void** ppv )
{
	if (iid == IID_IUnknown)
	{
		*ppv = static_cast<IUnknown*>(this); 
	}
	else if (iid == __uuidof(IComWrapperImpl))
	{
		*ppv = static_cast<IComWrapperImpl*>(this);
	}
	else if (iid == __uuidof(spT))
	{
#if 1
		// You can query for the interface.
		return m_pUnknownInner->QueryInterface(iid,ppv); // 注意点
#else
		// Or you can return a cached pointer.
		*ppv = m_pIY;   // 注意点
		// Fall through so it will get AddRef'ed
#endif
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

template<class T>
ULONG __stdcall CComWrapperImpl<T>::Release()
{

}

template<class T>
ULONG __stdcall CComWrapperImpl<T>::AddRef()
{

}
