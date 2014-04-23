#include "interface.h"

[
	coclass,
	uuid("4ED3625F-9551-4cc0-81DA-864418A01D2D"),
	progid("CSimpleAttrComCom.CSimpleAttrComCom.1"),
	version("1.0"),
	threading(single),
	default(ISimpleAttrCom)
]

class CSimpleAttrComCom:public ISimpleAttrCom
{
public:
	CSimpleAttrComCom();
	virtual ~CSimpleAttrComCom();
protected:
	virtual  HRESULT __stdcall TestAdd();
private:
};