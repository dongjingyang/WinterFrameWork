
#ifndef WINTER_AUTUMNLOG_H
#define WINTER_AUTUMNLOG_H

#include "ILogAdapter.h"
//#include "IBeanWrapper.h"

namespace Winter{

/** 
 * Logger for WinterFramework
 */
class WinterLog{
private:
	/** the true logger */
	ILogAdapter * Logger;

	/** the logger is default or not */
	bool isDefault;

	/** The singleton's instance */
	static WinterLog* Instance;

	/** Constructor, logger is NULL */
	WinterLog();

public:
	/** Destructor */
	~WinterLog();

	/** Get this singleton's instance */
	static WinterLog* getInstance();

	/** Set property logger from a bean*/
	void injectLogger(ILogAdapter* ilogger);

	/** Set property logger for default */
	void setDefaultLogger();

	void debug(const string& msg){
		if( this->Logger ) 
			this->Logger->debug(msg);
	}

	void info(const string& msg){
		if( this->Logger ) 
			this->Logger->info(msg);
	}

	void warn(const string& msg){
		if( this->Logger ) 
			this->Logger->warn(msg);
	}

	void error(const string& msg){
		if( this->Logger ) 
			this->Logger->error(msg);
	}

	void fatal(const string& msg){
		if( this->Logger ) 
			this->Logger->fatal(msg);
	}

	void log(int level, const string& msg){
		if( this->Logger ) 
			this->Logger->log(level, msg);
	}

};

} // End namespace Winter

#endif
