#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

// Status: Accepted

using namespace std;

map<string, string> letterMap =
{
	{"2", "abc"}, {"3", "def"}, {"4", "ghi"}, {"5", "jkl"}, {"6", "mno"}, {"7", "pqrs"}, {"8", "tuv"}, {"9", "wxyz"}
};

vector<string> letterCombinations(string digits);

//int main() {
//	vector<string> result = letterCombinations("23");
//	for (string str : result) {
//		cout << str << " ";
//	}
//}

vector<string> letterCombinations(string digits) {
	if (digits.size() == 0) {
		return vector<string>();
	}
	else if (digits.size() == 1) {
		vector<string> v;
		string value = letterMap[digits];
		for (int i = 0; i < value.size(); i++) {
			string tmp(1, value.at(i));
			v.push_back(tmp);
		}
		return v;
	}
	else {
		string key(1, digits[0]);
		//cout << "Key: " << key << endl;
		string value = letterMap[key];
		//cout << "Value: " << value << endl;
		string dig = digits.substr(1, digits.size() - 1);
		//cout << "Digit: " << dig << endl;
		vector<string> v = letterCombinations(dig);
		vector<string> result;
		for (int i = 0; i < value.size(); i++) {
			string s(1, value.at(i));
			for (string str : v) {
				cout << str << endl;
				string r = s + str;
				result.push_back(r);
			}
		}

		return result;
	}
}
