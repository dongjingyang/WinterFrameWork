
#ifndef XMlResource_DcomImpl_h__
#define XMlResource_DcomImpl_h__
#include "IResource.h"


namespace Winter
{
	class XmlResouce_DcomImpl:public CXmlMine::CXmlMine
	{
	public:
		XmlResouce_DcomImpl(const TCHAR* path);
		virtual ~XmlResouce_DcomImpl();

		HRESULT parseLibrary( XMLNode& xml, TLibrary& lib );

		HRESULT parseBean( XMLNode& xml, TBean& bean );

		HRESULT parseProperty( XMLNode& xml, TProperty& prop, bool isProp );

		string getErrorMsg( XMLResults& err, const char* tag );

		bool boolAttribute( const TString& value, const TString& name );
	protected:
	private:

	};//class XmlResouce_DcomImpl
}


#endif // XMlResource_DcomImpl_h__
