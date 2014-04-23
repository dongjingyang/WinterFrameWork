#include <oaidl.h>
[emitidl];

[
	object,
	dual,
	uuid("2C2CD1DC-4B13-431e-B4CF-B0BABF76BFA7")
]
__interface ISimpleAttrCom : public IDispatch {
	[id(1)] HRESULT TestAdd();
};

[
	object,
	dual,
	uuid("0B53220A-C679-4c42-A3B1-C3A432216B25")
]
__interface IWComImpl : public IDispatch {
	[id(1)] HRESULT Test1();
};


struct INondelegatingUnknown
{
	virtual HRESULT __stdcall
		NondelegatingQueryInterface(const IID&, void**) = 0;
	virtual ULONG __stdcall NondelegatingAddRef() = 0;
	virtual ULONG __stdcall NondelegatingRelease() = 0;
};