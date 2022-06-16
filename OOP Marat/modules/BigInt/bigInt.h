#include <iostream>
#include <string>
#include <ostream>

using namespace std;

#ifndef BIGINT_H
#define BIGINT_H


class bigInt{

// private:
private:
	string num;

	bool negative;	

	string reverse(string str);

	bool isBigger(string left, string right);

public:

	string add(string left, string right);

	string sub(string left, string right);

	string mul(string str, int m);

	bigInt(string val = "0");

	bigInt operator+(bigInt other);

    bigInt operator-(bigInt other);

    bigInt operator*(bigInt other);    

	bool isNeg();

    string getVal();
};

ostream& operator<<(ostream& os, bigInt& num);

#endif
