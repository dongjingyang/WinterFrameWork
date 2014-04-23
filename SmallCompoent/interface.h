#ifndef interface_h__
#define interface_h__

MIDL_INTERFACE("{F5659CCB-88B1-42fd-A998-E9A0923F120B}")
ITestDsCom:public IUnknown
{
	STDMETHOD(SayHelloWorld)(LPCTSTR lpszSaySth) PURE;
};
#endif // interface_h__


