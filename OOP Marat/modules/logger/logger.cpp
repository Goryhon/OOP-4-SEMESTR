#include "logger.h"

void LoggerCMD::error(string message) {
	time_t givemetime = time(NULL);
	cout<<"Error: "<<message<<" at "<<ctime(&givemetime)<<endl;
}

void LoggerCMD::warning(string message) {
	time_t givemetime = time(NULL);
	cout<<"Warning: "<<message<<" at "<<ctime(&givemetime)<<endl;
}

void LoggerCMD::info(string message) {
	time_t givemetime = time(NULL);
	cout<<"Info: "<<message<<" at "<<ctime(&givemetime)<<endl;
}


//LOGGER FILE -----------------------------------
LoggerFILE::LoggerFILE(string fname){
	fout.open(fname);
}

LoggerFILE::~LoggerFILE(){
	fout.close();
}

void LoggerFILE::error(string message) {
	time_t givemetime = time(NULL);
	fout<<"Error: "<<message<<" at "<<ctime(&givemetime)<<endl;
}

void LoggerFILE::warning(string message) {
	time_t givemetime = time(NULL);
	fout<<"Warning: "<<message<<" at "<<ctime(&givemetime)<<endl;
}

void LoggerFILE::info(string message) {
	time_t givemetime = time(NULL);
	fout<<"Info: "<<message<<" at "<<ctime(&givemetime)<<endl;
}

//LOGGER SEMI -----------------------------------

LoggerSEMI::LoggerSEMI(LoggerCMD** c, LoggerFILE** f){
	lFiel = *f;
	lCmd = *c;
}

LoggerSEMI::~LoggerSEMI(){
	delete(lFiel);
	delete(lCmd);
}

void LoggerSEMI::error(string message) {
	lFiel->error(message);
	lCmd->error(message);
}

void LoggerSEMI::warning(string message) {
	lFiel->warning(message);
	lCmd->warning(message);
}

void LoggerSEMI::info(string message) {
	lFiel->info(message);
	lCmd->info(message);
}

// FABRICS -------------------------------------------
//----------------------------------------------------

ILogger* LoggerCMDFact::create(){
	return new LoggerCMD();
}

LoggerFILEFact::LoggerFILEFact(string name){
	fname = name;
}

ILogger* LoggerFILEFact::create(){
	return new LoggerFILE(fname);
}

LoggerSEMIFact::LoggerSEMIFact(string name){
	fname = name;
}

ILogger* LoggerSEMIFact::create(){
	LoggerCMD* c = new LoggerCMD();
	LoggerFILE* f = new LoggerFILE(fname);
	return new LoggerSEMI(&c, &f);
}
