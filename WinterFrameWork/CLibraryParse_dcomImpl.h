
#ifndef CLibraryParse_dcomImpl__
#define CLibraryParse_dcomImpl__
#include "LibraryParser.h"

using namespace  std;
namespace Winter
{


	class CLibraryParse_dcomImpl:public CLibraryParser::CCLibraryParser
	{
	public:
		CLibraryParse_dcomImpl();
		~CLibraryParse_dcomImpl();

		virtual bool ParseLibrary( XMLNode& xml, TLibrary& lib );
	private:

		bool parseBean(XMLNode beanNode, shared_ptr<TBean> spBean);
		bool boolAttribute(const DS_String value);
	};

}
#endif // CLibraryParse_impl_h__
