#include <iostream>
#include <ostream>
#include <fstream>
#include <stdexcept>

using namespace std;

#ifndef CSV_H
#define CSV_H

class node{
public:
	node* next = NULL;
	string *row;
	// node(T v);
	void clear();
};

class csv{
private:
	int len = 0;
	int col = 0;

	int find_col(string str);

	void parse_str(string **row, string str);

public:
	node *head = NULL;
	string ** arr;
	void parse(string name);
	int length();
	int columns();
    void write_to_file(const string& path);
    void write_to_file(const string& path, string** table, int height, int width);
};


#endif