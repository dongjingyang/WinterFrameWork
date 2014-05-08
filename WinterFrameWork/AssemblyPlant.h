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
		HRESULT AssemblyLibrary(CXmlMine* xmlMine);
	};
}


