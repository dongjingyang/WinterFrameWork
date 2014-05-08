#pragma once
#include "DCom.h"
#include "interface.h"
#include "DComClassImpl.h"
using namespace  dscom;

// {5655A698-ED5F-47cc-B132-11249F4D823A}
static const GUID CLSID_SmallCompoent = 
{ 0x5655a698, 0xed5f, 0x47cc, { 0xb1, 0x32, 0x11, 0x24, 0x9f, 0x4d, 0x82, 0x3a } };

class  CSmallCompoent:public ITestDsCom,
	public CDSClassImpl<CSmallCompoent>,
	public CUnknownImp
{
public:
	UNKNOWN_IMP1(ITestDsCom);
	CSmallCompoent(void);
	virtual ~CSmallCompoent();
public:
	STDMETHOD(init_class)(IDComBase * prot, IDComBase* punkOuter)
	{
		if (prot) { m_pRot = prot; }
		if (punkOuter) { m_pUnknonwnOuter = punkOuter; }
		return S_OK;
	}
	STDMETHOD(SayHelloWorld)(LPCTSTR lpszSaySth);
private:
	
};
