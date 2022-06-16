#include <iostream>
#include <stdexcept>

using namespace std;

#ifndef DICT_H
#define DICT_H

template <typename T>
class dict{
private:
	int cur = -1;
	int max = 0;
	int step = 0;

	string *index;
	T *val;

	int find_index(string ind);

public:
	dict(int size = 4, int s = 4);
	T& operator[](string ind);
    bool has(string val);
    int length();
    string* get_keys();
};

template <typename T>
int dict<T>::find_index(string ind){
    int ret = -1;
    for(int i = 0; i <= cur; i ++){
        if(index[i] == ind){
            ret = i;
            break;
        }
    }
    return ret;
}

template <typename T>
dict<T>::dict(int size, int s){
    index = new string[size];
    val = new T[size];
    max = size;
    step = s;
}

template <typename T>
T& dict<T>::operator[](string ind){
    int i = find_index(ind);
    if(i < 0){
        cur ++;

        if(cur >= max){
            string *new_ind = new string[max + step];
            T *new_val = new T[max + step];
            for(int i = 0; i < cur; i++){
                new_ind[i] = index[i];
                new_val[i] = val[i];
            }

            max += step;
            delete []index;
            delete []val;

            index = new_ind;
            val = new_val;
        }

        index[cur] = ind;
        return val[cur];
    }
    else{
        return val[i];
    }
}

template<typename T>
bool dict<T>::has(string val) {
    return find_index(val) != -1;
}

template<typename T>
int dict<T>::length() {
    return cur + 1;
}

template<typename T>
string *dict<T>::get_keys() {
    string* res = new string[this->length()];
    for (int i = 0; i < this->length(); i++) {
        res[i] = this->index[i];
    }
    return res;
}

#endif