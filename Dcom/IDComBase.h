
#ifndef IDComBase_h__
#define IDComBase_h__



#include <unknwn.h>

#define IDComBase			IUnknown



#define DC_DEFINE_IID(iface, uuid_string)	struct __declspec(uuid(uuid_string)) iface
#define de_uuidof(iface)	__uuidof(iface)
#define DC_DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	EXTERN_C const GUID DECLSPEC_SELECTANY name \
	= { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

#endif // IDComBase_h__