#pragma once
#include "RunningObjTable.h"

namespace Winter
{
	class CXmlMine;
	class CRunningObjTable;
	class CAssemblyPlant
	{
	public:
		CAssemblyPlant(CXmlMine* xmlMine);
		~CAssemblyPlant();
	private:
		CRunningObjTable	m_Rot;
		HRESULT AssemblyLibrary(CXmlMine* xmlMine);
	};
}


