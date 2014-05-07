#include "Bean.h"
namespace Winter
{

	CBean::CBean(CCBean* pCCbean):_p(pCCbean)
	{

	}


	CBean::~CBean()
	{
	}

	HRESULT CBean::GetBean(LPCTSTR lpcsObjId, void ** pOuter)
	{
		return _p->GetBean(lpcsObjId, pOuter);
	}

}



