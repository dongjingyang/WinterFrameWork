
#ifndef XMlResource_DcomImpl_h__
#define XMlResource_DcomImpl_h__
#include "IResource.h"


namespace Winter
{
	class XmlResouce_DcomImpl :public CLibraryParser::CCLibraryParser
	{
	public:
		XmlResouce_DcomImpl(const TCHAR* path);
		virtual ~XmlResouce_DcomImpl();

		HRESULT parseLibrary( XMLNode& xml, TLibrary& lib );
	private:
		HRESULT parseBean( XMLNode& xml, TBean& bean );

		HRESULT parseProperty( XMLNode& xml, TProperty& prop, bool isProp );

		string getErrorMsg( XMLResults& err, const char* tag );

		bool boolAttribute( const TString& value, const TString& name );
	protected:
	};//class XmlResouce_DcomImpl
}


#endif // XMlResource_DcomImpl_h__
