
#ifndef WINTER_XMLRESOURCE_H
#define WINTER_XMLRESOURCE_H

#include <vector>
#include <string>
#include "xmlParser.h"
#include "IResource.h"
#include "WinterDefinition.h"

namespace Winter{

class XMLResource: public IResource{
private:
	/** All libraries configuration */
	vector<TLibrary*> LibsConfig;

	/** Parse library */
	void parseLibrary(XMLNode& xml, TLibrary& lib);

	/** Parse bean */
	void parseBean(XMLNode& xml, TBean& bean);

	/** Parse Property */
	void parseProperty(XMLNode& xml, TProperty& prop, bool isProp);

	/** Get parsing error message */
	string getErrorMsg(XMLResults& err, const char* tag);

	/** convert value to true or false */
	bool boolAttribute(const TString& value, const TString& name);
public:
	/** 
	 * Constructor, parse XML file 
	 * @param path XML file path
	 */
	XMLResource(const TCHAR* path);

	/** Destructor */
	~XMLResource(){
		for(int i=0; i<this->LibsConfig.size(); i++)
			delete this->LibsConfig[i];
	}

	/** Return all libraries configuration */
	const vector<TLibrary*>* getLibraries() const{
		return &this->LibsConfig;
	}
};

} // End namespace Winter
#endif
