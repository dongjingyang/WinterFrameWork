#include "XMlResource_DcomImpl.h"
#include "WinterDefinition.h"

namespace Winter
{
	XmlResouce_DcomImpl::XmlResouce_DcomImpl(const TCHAR* path)
	{

	}

	XmlResouce_DcomImpl::~XmlResouce_DcomImpl()
	{

	}

	HRESULT XmlResouce_DcomImpl::parseLibrary( XMLNode& xml, TLibrary& lib )
	{
		return S_OK;
	}

	HRESULT XmlResouce_DcomImpl::parseBean( XMLNode& xml, TBean& bean )
	{
		return S_OK;
	}

	HRESULT XmlResouce_DcomImpl::parseProperty( XMLNode& xml, TProperty& prop, bool isProp )
	{
		return S_OK;
	}

	testing::internal::string XmlResouce_DcomImpl::getErrorMsg( XMLResults& err, const char* tag )
	{
		return S_OK;
	}

	bool XmlResouce_DcomImpl::boolAttribute( const TString& value, const TString& name )
	{
		return S_OK;
	}
}


