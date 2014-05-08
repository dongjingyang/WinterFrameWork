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
		RETURN_TRUE((!m_mapRunningTable.empty())&&iterTemp == m_mapRunningTable.end(), E_INVALIDARG);
		m_mapRunningTable.insert(Rot_Pair(PreProcessObjName(lpcsObjectName).get(), punkObject));
		return S_OK;
	}

	HRESULT CRunningObjTable::GetObject(LPCTSTR lpcsObjectName, LPCTSTR lpcsBeanID, void ** punkObject)
	{
		HRESULT hr = E_FAIL;
		RUNNINGOBJTABLE::const_iterator   iterTemp = m_mapRunningTable.find(PreProcessObjName(lpcsObjectName).get());
		RETURN_TRUE(iterTemp == m_mapRunningTable.end(), E_NOINTERFACE);
		CBean * beanTemp = iterTemp->second;
		HRTHREOWEX(beanTemp, NonValue, "bean is not in table", E_FAIL);
		hr = beanTemp->GetBean(lpcsBeanID, punkObject);
		FAILEDRETURN(hr);
		HRTHREOWEX(punkObject, NonValue, "the object is null", E_FAIL);
		return S_OK;
	}

	shared_ptr<TCHAR> CRunningObjTable::PreProcessObjName(LPCTSTR lpcsObjectName)
	{
		shared_ptr<TCHAR> spTName(new TCHAR[MAX_GUID]);
		_tcscpy(spTName.get(),  lpcsObjectName);
		_tcslwr_s(spTName.get(), _tcslen(spTName.get()) + 1);
		return spTName;
	}

}

