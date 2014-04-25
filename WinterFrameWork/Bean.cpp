#include "Bean.h"
namespace Winter
{

	CBean::CBean()
	{
	}


	CBean::~CBean()
	{
	}

	HRESULT CBean::GetObject(DS_String lpcsObjId, void ** pOuter)
	{
		return _p->GetObject(lpcsObjId, pOuter);
	}

}



