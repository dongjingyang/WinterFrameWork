
#ifndef XmlMine_h__
#define XmlMine_h__

#include "WinterDefinition.h"
#include "LibraryTemplate.h"



class XMLNode;
class XMLResults;
class CLibraryParser;
class CLibraryParse_dcomImpl;
namespace Winter
{
	typedef std::vector<shared_ptr<TLibrary>>    DS_LIBRARYVEC;
	typedef std::vector<shared_ptr<TBean>>		DS_BEANSVEC;
#ifndef ASSEMPARSER
#define  ASSEMPARSER(libType,xml,lib)\
	ASSEMPARSER_(libType,xml,lib)
#define  ASSEMPARSER_(libType,xml,lib)\
	CLibraryParser temp(new CLibraryParse_##libType##Impl());\
	temp.ParseLibrary(xml,lib);
#endif

	class CXmlMine
	{
	public:
		CXmlMine(const TCHAR * tPath);
		virtual ~CXmlMine();

		DS_LIBRARYVEC* GetVecLibrary();
		int GetLibraryCount();
	private: 
		/** Parse library */
		HRESULT parseLibrary(XMLNode& xml, TLibrary& lib);

		/** Parse bean */
		HRESULT parseBean(XMLNode& xml, TBean& bean);
		string getErrorMsg(XMLResults& err, const TCHAR* tag);
	private:

		DS_LIBRARYVEC						m_vecLibrary;
		DS_BEANSVEC							m_vecBeans;
	};


}//name space


#endif // XmlMine_h__



