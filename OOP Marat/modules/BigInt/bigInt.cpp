#include "bigInt.h"

string bigInt::reverse(string str){
	char temp;
	for(int i = 0; i < str.length()/2; i++){
		temp = str[i];
		str[i] = str[str.length() - i - 1];
		str[str.length() - i - 1] = temp;
	}
	return str;
}

bool bigInt::isBigger(string left, string right){
	if(left.length() > right.length())
		return true;
	if(left.length() == right.length()){
		for(int i = 0; i < left.length(); i++){
			if(left[i] > right[i])
				return true;
			else if(left[i] < right[i])
				return false;
		}
		return false;
	}
	return false;

}

bigInt::bigInt(string val){
	if(val[0] == '-'){
		negative = true;
		val.erase(0,1);
	}
	else{
		negative = false;
	}

	while(val[0] == '0'){
		val.erase(0, 1);
	}

	bool valid = true;
	for(int i = 0; i < val.length() && valid; i++){
		if(val[i] < '0' || val[i] > '9'){
			valid = false;
		}
	}

	if(!valid || val.length() == 0){
		val = "0";
	}
	num = val;
}

string bigInt::add(string left, string right){
	if(left.length() < right.length()){
		string temp = left;
		left = right;
		right = temp;
	}

	left = '0' + left;
	while(right.length() < left.length()){
		right = '0' + right;
	}

	string result = "";

	int buffer = 0;
	for(int i = left.length() - 1; i >= 0; i--){
		int temp =  left[i] + right[i] - (2 * '0') + buffer;
		result += '0' + temp%10;
		buffer = temp/10;
	}
	result = reverse(result);
	while(result[0] == '0'){
		result.erase(0,1);
	}
	return result;
}

string bigInt::sub(string left, string right){
	while(right.length() < left.length()){
		right = '0' + right;
	}

	int buffer = 0;

	for(int i = left.length() - 1; i >= 0; i--){
		int temp = left[i] - right[i] - buffer;
		buffer = 0;
		if(temp < 0){
			buffer = 1;
			temp += 10;
		}
		left[i] = temp + '0';
	}
	return left;
}

string bigInt::mul(string str, int m){
	string res = '0' + str;
	int buffer = 0;
	for(int i = str.length() - 1; i >= 0; i--){
		// cout<<"S "<<str[i]<<endl;
		buffer = (str[i] - '0')*m + buffer;
		res[i + 1] = buffer%10 + '0';
		buffer /= 10;
	}
	res[0] = buffer + '0';
	return res;
}

bigInt bigInt::operator+(bigInt other){
	
	string res = "0";
	switch (negative + other.isNeg()*2){
		case 0:
			res = add(num, other.getVal());
		break;

		case 3:
			res = '-' + add(num, other.getVal());
		break;

		case 1:
			if(isBigger(num, other.getVal())){
				res = '-' + sub(num,other.getVal());
			}
			else{
				res = sub(other.getVal(), num);
			}
		break;

		case 2:
			if(isBigger(num, other.getVal())){
				res = sub(num,other.getVal());
			}
			else{
				res = '-' + sub(other.getVal(), num);
			}
		break;
	}
	// string res = add(num, other.getVal());

	return bigInt(res);
}

bigInt bigInt::operator-(bigInt other){
	
	string res = "0";
	switch (negative + other.isNeg()*2){
		case 0:

			if(isBigger(num, other.getVal())){
				res = sub(num,other.getVal());
			}
			else{
				res = '-' + sub(other.getVal(), num);
			}

		break;

		case 3:

			if(isBigger(num, other.getVal())){
				res = '-' + sub(num,other.getVal());
			}
			else{
				res = sub(other.getVal(), num);
			}

		break;

		case 1:

			res = '-' + add(num, other.getVal());
			
		break;

		case 2:

			res = add(num, other.getVal());
			
		break;
	}
	// string res = add(num, other.getVal());

	return bigInt(res);
}

bigInt bigInt::operator*(bigInt other){
	string left = num;
	string right = other.getVal();
	if (isBigger(right, left)){
		string temp = right;
		right = left;
		left = temp;
	}
	string res = "0";
	string buffer = "";
	for (int i = right.length() - 1; i >= 0; i--){
//		cout<<"i "<<i<<endl;
		res = add(res, mul(left + buffer, right[i] - '0'));
		buffer += '0';
	}

	if(negative != other.isNeg()){
		res = '-' + res;
	}
	// res = "1";
	return bigInt(res);
}

bool bigInt::isNeg(){
	return negative;
}

string bigInt::getVal(){
    return num;
}

ostream& operator<<(ostream& os, bigInt& num){
	if(num.isNeg()){
		os<<'-';
	}
	return os<<num.getVal();
}