// dllmain.h : Declaration of module class.

class CTestComLibraryModule : public CAtlDllModuleT< CTestComLibraryModule >
{
public :
	DECLARE_LIBID(LIBID_TestComLibraryLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TESTCOMLIBRARY, "{78CE52C8-050B-4D84-A960-2D790CA44BD9}")
};

extern class CTestComLibraryModule _AtlModule;
