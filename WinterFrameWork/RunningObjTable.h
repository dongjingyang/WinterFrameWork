#pragma once

#include "basic.h"
#include <map>
using namespace std;
namespace Winter
{
	class CBean;
	class CRunningObjTable
	{
	public:
		CRunningObjTable();
		~CRunningObjTable();
	public:
		HRESULT   Regesiter(LPCTSTR  lpcsObjectName, CBean * punkObject);
		HRESULT   GetObject(LPCTSTR  lpcsObjectName,LPCTSTR lpcsBeanID,void ** punkObject);
		static CRunningObjTable & Instance()
		{
			static CRunningObjTable DsRot;
			return DsRot;
		}
	private:
		typedef  map<LPCTSTR, CBean *>  RUNNINGOBJTABLE;
		RUNNINGOBJTABLE							m_mapRunningTable;
	};
}


