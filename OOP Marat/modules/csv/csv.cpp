#include "csv.h"
#include <string>

void node::clear(){
	if(next != NULL){
		next->clear();
	}
	delete(this);
}

int csv::find_col(string str){
	int col = 0;
	bool isStr = false;
	for(int i = 0; i < str.length(); i++){
		if(!isStr && str[i] == ','){
			col++;
		}
		if(str[i] == '\"'){
			isStr = !isStr;
		}
	}
	return col + 1;
}

void csv::parse_str(string **row, string str){
	*row = new string[col];
	string temp = "";
	bool isStr = false;
	int counter = 0;
	for(int i = 0; i < str.length(); i++){
		if(!isStr && str[i] == ','){
			(*row)[counter] = temp;
			counter++;
			temp = "";
		}
		else{
			if(str[i] == '\"'){
				isStr = !isStr;
			}
			temp += str[i];
		}
	}
	(*row)[counter] = temp;
}

void csv::parse(string name){

	if(head != NULL){
		head->clear();
	}

	for(int i = 0; i < len; i++){
		delete [] arr[i];
	}

	if(len > 0){
		delete []arr;
	}

	len = 0;

	ifstream fin;
	fin.open(name);

	string row;


	getline(fin, row);
	len ++;
	head = new node();
	col = find_col(row);

	parse_str(&(head->row), row);

	node *temp = head;

	while(getline(fin, row)){
		// cout<<row<<endl;
		temp->next = new node;
		temp = temp->next;
		parse_str(&(temp->row), row);

		len++;
	}

	arr = new string*[len];

	temp = head;
	int counter = 0;
	while(temp != NULL){
		arr[counter] = new string[col];
		for(int i = 0; i < col; i++){
			arr[counter][i] = temp->row[i];
		}
		counter ++;
		temp = temp->next;
	}
}

int csv::length(){
	return len;
}

int csv::columns(){
	return col;
}

void csv::write_to_file(const string &path) {
    ofstream out(path);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1)
                out << arr[i][j];
            else
                out << arr[i][j] << ",";
        }
        out << "\n";
    }
    out.close();
}

void csv::write_to_file(const string &path, string **table, int height, int width) {
    ofstream out(path);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == width - 1)
                out << table[i][j];
            else
                out << table[i][j] << ",";
        }
        out << "\n";
    }
    out.close();
}
