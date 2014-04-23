
#ifndef LibraryParser_h__
#define LibraryParser_h__
#include "xmlParser.h"
#include "LibraryTemplate.h"
namespace Winter
{

	class CLibraryParser
	{
	public:
		class CCLibraryParser
		{
		public:
			virtual bool ParseLibrary(XMLNode& xml, TLibrary& lib) = 0;

		protected:
		private:
		};

		CLibraryParser(CLibraryParser::CCLibraryParser *p):_pLibraryParser(p)
		{

		}
		virtual   ~CLibraryParser()
		{}
		bool ParseLibrary(XMLNode& xml, TLibrary& lib){return _pLibraryParser->ParseLibrary(xml,lib);}
	protected:
	private:
		CCLibraryParser    *_pLibraryParser;
	};
}
#endif // LibraryParser_h__
