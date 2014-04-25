#ifndef DComClassImpl_h__
#define DComClassImpl_h__

#include "DComUtility.h"



template<typename T>
class CDSClassImpl
{
public:
	STDMETHOD(init_class)(IDComBase * prot, IDComBase* punkOuter)
	{
		if(prot) {m_pRot = prot;}
		if(punkOuter) {m_pUnknonwnOuter = punkOuter;}
		return S_OK;
	}
	UTIL::com_ptr<IDComBase> GetRot(){return m_pRot;}//全局运行对象表，以后实现
	UTIL::com_ptr<IDComBase> GetOuter(){return m_pUnknonwnOuter;}
protected:
	UTIL::com_ptr<IDComBase> m_pRot;
	UTIL::com_ptr<IDComBase> m_pUnknonwnOuter;
};

#endif // DComClassImpl_h__