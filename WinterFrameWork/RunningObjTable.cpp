#include "RunningObjTable.h"
#include "Bean.h"
namespace Winter
{
	CRunningObjTable::CRunningObjTable()
	{
	}


	CRunningObjTable::~CRunningObjTable()
	{
	}

	HRESULT CRunningObjTable::Regesiter(LPCTSTR lpcsObjectName, CBean * punkObject)
	{
		if (m_mapRunningTable.end() !=  m_mapRunningTable.find(lpcsObjectName))
		{
		}
		m_mapRunningTable[lpcsObjectName] = punkObject;
		return S_OK;
	}

	HRESULT CRunningObjTable::GetObject(LPCTSTR lpcsObjectName, CBean ** punkObject)
	{
		return S_OK;
	}

}

