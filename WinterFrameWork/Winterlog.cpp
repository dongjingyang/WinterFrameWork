

#include "WinterLog.h"
//#include "ConsoleLogger.h"
#include "FileLogger.h"

namespace Winter{

WinterLog* WinterLog::Instance = NULL;
const string DefaultLogPath = "WinterFramework.log";
const int DefaultLogLevel = 2;

WinterLog::WinterLog()
{
	this->Logger = NULL;
	this->isDefault = false;
	this->setDefaultLogger();
}

WinterLog::~WinterLog()
{
	if( this->isDefault) 
		delete this->Logger;
}

/** Get this singleton's instance */
WinterLog* WinterLog::getInstance()
{
	if( WinterLog::Instance == NULL)
		WinterLog::Instance = new WinterLog();
	return WinterLog::Instance;
}

/** Set property logger */
void WinterLog::injectLogger(ILogAdapter* ilogger)
{
	if( this->isDefault ) delete this->Logger;
	this->Logger = ilogger;
	this->isDefault = false;
}

void WinterLog::setDefaultLogger()
{
	if( ! this->isDefault ) {
		this->Logger = new FileLogger(DefaultLogPath, DefaultLogLevel);
		this->isDefault = true;
	}
}

} // End namespace Winter

