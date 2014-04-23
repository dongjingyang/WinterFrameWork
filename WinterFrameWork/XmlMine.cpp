#include "XmlMine.h"
#include "xmlParser.h"
#include "WinterException.h"
#include "LibraryTemplate.h"
#include "LibraryParser.h"
#include "CLibraryParse_dcomImpl.h"
#include "string.h"

namespace Winter
{
	CXmlMine::CXmlMine( const TCHAR * tPath )
	{
		XMLCSTR rootTag=_T("winter");
		XMLCSTR libTag=_T("library");
		XMLResults errRlt;

		XMLNode rootNode = XMLNode::parseFile(tPath, rootTag, &errRlt);
		if( errRlt.error != eXMLErrorNone )
		{
			if( errRlt.error == eXMLErrorFileNotFound )
			{
				THREOWEXCETION(XMLParsing, "File not found: ");
			}
			else{
				THREOWEXCETION(XMLParsing, string("Error when parsing file '") + ", err.line =" + toString<int>(errRlt.nLine));
			}
		}

		int i, pos=0, n = rootNode.nChildNode(libTag);
		for(i=0; i<n; i++)
		{
			TLibrary *plib = new TLibrary;
			XMLNode libNode = rootNode.getChildNode(libTag, &pos);
			parseLibrary(libNode, *plib);
			this->m_vecLibrary.push_back(plib);
		}
		if (n == 0)
			THREOWEXCETION(XMLParsing, string("Error when parsing tag '") +"'. There is no element '" + "'.");
	}

	CXmlMine::~CXmlMine()
	{
		for(size_t i=0; i<this->m_vecLibrary.size(); i++)
			delete this->m_vecLibrary[i];
	}

	HRESULT CXmlMine::parseLibrary( XMLNode& xml, TLibrary& lib )
	{
		XMLCSTR beanTag=_T("bean");

		// parsing attributes
		XMLCSTR name = xml.getAttribute(_T("name"));
		XMLCSTR path = xml.getAttribute(_T("path"));
		XMLCSTR type   = xml.getAttribute(_T("type"));

		if( name != NULL ) lib.tName = name;
		if( path != NULL ) lib.tPath = path;
		if( type   != NULL ) lib.tType   = type;

		if( lib.tPath.empty() )
		{
			THREOWEXCETION(XMLParsing, string("Error when parsing library '") + "'. There is no path.");
		}

		if( lib.tName.empty() )
		{
			lib.tName = lib.tPath;
		}

		if (lib.tType.empty())
		{
			lib.tType = STR_TYPE_DCOM;
		}
		if (0 == _tcsnicmp(lib.tType.c_str(), STR_TYPE_DCOM, 4))
		{
			ASSEMPARSER(DCOM,xml,lib);
		}
		else
		{
			return S_OK;
		}


		return S_OK;
	}

	HRESULT CXmlMine::parseBean( XMLNode& xml, TBean& bean )
	{


		return S_OK;
	}

	DS_LIBRARYVEC* CXmlMine::GetVecLibrary()
	{
		return &m_vecLibrary;
	}

	int CXmlMine::GetLibraryCount()
	{
		return m_vecLibrary.size();
	}


}
