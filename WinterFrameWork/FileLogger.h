
#ifndef WINTER_FILELOGGER_H
#define WINTER_FILELOGGER_H

#include <ctime>
#include <string>
#include <fstream>
#include "ILogAdapter.h"
#include "WinterException.h"
#include "basic.h"

using namespace std;

namespace Winter{

/** 
 * Adapter for external log implementation
 * @version 0.1.0
 * @since 2006-11-30
 */

class FileLogger: public ILogAdapter {
private:
	/** Log level */
	int Level;

	ofstream Of;

	string getTime(){
		char buf[100];
		time_t tim;
		
		time(&tim);
		tm timeinfo = {0}; 
		localtime_s(&timeinfo,&tim);
		strftime(buf, 100, "%Y-%m-%d %H:%M:%S",&timeinfo);
		return string(buf);
	}

public:
	FileLogger(const string& filepath, int level):Level(level){
		this->Of.open(filepath.c_str(), ios::out | ios::app);
		if (!this->Of.is_open())
			THREOWEXCETION(InitExce, string("Can't open file[" + filepath + "]."));
	}
	
	void debug(const string& msg){
		this->log(0, "DEBUG: " + msg);
	}

	void info(const string& msg){
		this->log(1, "INFO: " + msg);
	}
	
	void warn(const string& msg){
		this->log(2, "WARN: " + msg);
	}
	
	void error(const string& msg){
		this->log(3, "ERROR: " + msg);
	}
	
	void fatal(const string& msg){
		this->log(4, "FATAL: " + msg);
	}
	
	void log(int level, const string& msg){
		if( level >= this->Level ){
			this->Of<<this->getTime()<<" "<<msg<<endl;
		}
	}
};

} // End namespace Winter
#endif
