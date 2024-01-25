#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

// Status: Accepted

using namespace std;

string reverseWords(string);

//int main() {
//	string s = "the sky is blue";
//	string res = reverseWords(s);
//	cout << res << endl;
//}

string reverseWords(string s) {
	istringstream iss(s);
	vector<string> vec(istream_iterator<string>{iss}, istream_iterator<string>());
	string str;
	
	for (auto i = vec.rbegin(); i != vec.rend(); i++) {
		str += *i;
		if ((i + 1) != vec.rend()) {
			str += " ";
		}
	}

	return str;
}

