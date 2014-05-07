#include "RunningObjTable.h"
#include "Bean.h"
#include "WinterException.h"
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
		RUNNINGOBJTABLE::const_iterator   iterTemp = m_mapRunningTable.find(lpcsObjectName);
		RETURN_TRUE(iterTemp == m_mapRunningTable.end(), E_NOINTERFACE);
		m_mapRunningTable[lpcsObjectName] = punkObject;
		return S_OK;
	}

	HRESULT CRunningObjTable::GetObject(LPCTSTR lpcsObjectName, LPCTSTR lpcsBeanID, void ** punkObject)
	{
		HRESULT hr = E_FAIL;
		RUNNINGOBJTABLE::const_iterator   iterTemp = m_mapRunningTable.find(lpcsObjectName);
		RETURN_TRUE(iterTemp == m_mapRunningTable.end(), E_NOINTERFACE);
		CBean * beanTemp = m_mapRunningTable[lpcsObjectName];
		HRTHREOWEX(beanTemp, NonValue, "bean is not in table", E_FAIL);
		hr = beanTemp->GetBean(lpcsBeanID, punkObject);
		FAILEDRETURN(hr);
		HRTHREOWEX(punkObject, NonValue, "the object is null", E_FAIL);
		return S_OK;
	}

}

