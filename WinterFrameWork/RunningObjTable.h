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
		HRESULT   GetObject(LPCTSTR  lpcsObjectName, LPCTSTR lpcsBeanID, void ** punkObject);
		static CRunningObjTable & Instance()
		{
			static CRunningObjTable DsRot;
			return DsRot;
		}
	private:
		typedef  map<DS_String, CBean *>  RUNNINGOBJTABLE;
		RUNNINGOBJTABLE							m_mapRunningTable;
		typedef pair <DS_String, CBean*> Rot_Pair;
		shared_ptr<TCHAR> PreProcessObjName(LPCTSTR lpcsObjectName);
	};
}


