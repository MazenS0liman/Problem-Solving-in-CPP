#include <iostream>
#include <string>

// Status: Wrong

using namespace std;

string gcdOfStrings(string str1, string str2);

//int main() {
//	string str1("ABCABC");
//	string str2("ABC");
//
//	string res = gcdOfStrings(str1, str2);
//	cout << "Result: " << res << endl;
//}

string gcdOfStrings(string str1, string str2) {
	string shortest = (str1.length() < str2.length()) ? str1 : str2;
	string longest = (str1.length() >= str2.length()) ? str1 : str2;
	int shortest_length = shortest.length();
	int longest_length = longest.length();
	string substring = "";

	cout << "Shortest: " << shortest << endl;
	cout << "Longest: " << longest << endl;

	for (int i = 0; i < shortest_length; i++) {
		substring = substring + shortest[i];
		int length = substring.length();
		bool state = true;

		if (shortest_length % length != 0)
			continue;

		for (int j = 0; j < shortest_length; j += length) {
			string sub = shortest.substr(j, length);
			if (sub != substring) {
				state = false;
				break;
			}
		}

		if (state)
			break;
	}

	cout << "Substring: " << substring << endl;

	int substring_length = substring.length();
	if (longest_length % substring_length != 0) {
		return "";
	}
	else {
		bool state = true;

		for (int j = 0; j < longest_length; j += substring_length) {
			string sub = longest.substr(j, substring_length);
			cout << "length: " << j << ", " << longest_length << endl;
			cout << "Sub: " << sub << endl;

			if (sub != substring) {
				state = false;
				break;
			}
		}

		if (state) {
			return substring;
		}
		else {
			return "";
		}
	}
}