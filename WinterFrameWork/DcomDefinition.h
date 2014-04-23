#ifndef DcomDefinition_h__
#define DcomDefinition_h__

namespace Winter
{

	/** struct to store property configuration */
	typedef struct{
		TString	Name;
	} TXmlProperty;

	/** struct to store bean configuration */
	typedef struct{
		/** bean name */
		TString	tName;

		/**bean clsid*/
		TString  tclsid;
	} DcomBean;

	/** struct to store library configuration */
	typedef struct{
		/** Library's name. "local" is special for main program */
		TString tName;

		/** Library file path. If name is "local", path is useless. */
		TString tPath;

		/**library Type*/
		TString  tTypeName;

		/** beans in library */
		vector<DcomBean> vecBeans;
	} DComLibrary;
};



#endif // DcomDefinition_h__