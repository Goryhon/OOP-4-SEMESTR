#include "logger.cpp"
// #include "logger.h"
#include <iostream>

using namespace std;

int main(){
	ILoggerFact* fact = new LoggerCMDFact();
	ILogger* cmd = fact->create();
	cmd->info("cmd log");

	fact = new LoggerFILEFact();
	ILogger* file = fact->create();
	file->info("file log");

	fact = new LoggerSEMIFact("slogs.txt");
	ILogger* semi = fact->create();
	semi->info("semi log");
}