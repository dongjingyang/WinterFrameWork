#ifndef LibraryTemplate_h__
#define LibraryTemplate_h__

#include "basic.h"

namespace Winter
{

	typedef struct
	{
		DS_String  tName;
		DS_String  tCLsid;
		DS_String	tClassName;
		bool		bIsSingleTon;

	}TBean;
	typedef struct  
	{
		DS_String	tName;
		DS_String	tPath;
		DS_String	tType;
		bool			bDelayLoad;

		vector<shared_ptr<TBean>>		vecBeans;
	}TLibrary;
}

#endif // LibraryTemplate_h__
