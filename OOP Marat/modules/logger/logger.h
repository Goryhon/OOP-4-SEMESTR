#include <iostream>
#include <fstream>
#include <time.h>
#pragma once

using namespace std;

class ILogger{
public:
	virtual void error(string message) = 0;
	virtual void warning(string message) = 0;
	virtual void info(string message) = 0;
};

class LoggerCMD : public ILogger{
public:
	void error(string message) override;
	void warning(string message) override;
	void info(string message) override;
};

class LoggerFILE : public ILogger{
private:
	ofstream fout;

public:
	LoggerFILE(string fname = "logs.txt");
	~LoggerFILE();

	void error(string message) override;
	void warning(string message) override;
	void info(string message) override;
};

class LoggerSEMI : public ILogger{
private:
	LoggerFILE* lFiel;
	LoggerCMD* lCmd;

public:
	LoggerSEMI(LoggerCMD** c, LoggerFILE** f);
	~LoggerSEMI();

	void error(string message) override;
	void warning(string message) override;
	void info(string message) override;
};

class ILoggerFact{
public:
	virtual ILogger* create() = 0;
};

class LoggerCMDFact: public ILoggerFact{
public:
	ILogger* create() override;
};

class LoggerFILEFact: public ILoggerFact{
public:
	string fname;
	LoggerFILEFact(string name = "logs.txt");
	ILogger* create() override;
};

class LoggerSEMIFact: public ILoggerFact{
public:
	string fname;
	LoggerSEMIFact(string name = "logs.txt");
	ILogger* create() override;
};
