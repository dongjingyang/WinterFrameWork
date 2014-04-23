// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "DCom.h"
#include "DComBase.h"
#include "SmallCompoent.h"
using namespace dscom;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

BEGIN_CLIDMAP
CLIDMAPENTRY_BEGIN
CLIDMAPENTRY_PROGID(CLSID_SmallCompoent, CSmallCompoent, _T("smallCompoent"))
CLIDMAPENTRY_END
END_CLIDMAP_AND_EXPORTFUN