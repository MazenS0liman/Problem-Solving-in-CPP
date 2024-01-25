#include <iostream>
#include <vector>
#include <string>

// Status: Accepted

using namespace std;

int compress(vector<char>&);

//int main() {
//	//{ 'a', 'a', 'b', 'b', 'c', 'c', 'c' }
//	vector<char> chars({ 'a', 'a', 'a', 'b', 'b', 'a', 'a' });
//	int size = compress(chars);
//	cout << "size = " << size << endl;
//	for (int i = 0; i < size; i++) {
//		cout << chars[i] << " ";
//	}
//
//}

int compress(vector<char>& chars) {
	int size = 0;
	int count = 0;
	char c;

	auto j = chars.begin();
	for (auto i = chars.begin(); i != chars.end(); i++) {
		if (i == chars.begin()) {
			c = *i;
			size = 1;
		}

		if (*i != c) {
			*j = c;
			j++;

			if (count != 1) {
				string str = to_string(count);
				for (int k = 0; k < str.size(); k++) {
					*j = str.at(k);
					j++;
					size++;
				}
			}

			count = 1;
			size++;
			c = *i;
			*j = c;
		}
		else {
			count++;
		}

		cout << c << endl;

	}

	if (count > 1) {
		j++;
		cout << "Last: " << c << endl;
		string str = to_string(count);
		for (int k = 0; k < str.size(); k++) {
			*j = str.at(k);
			j++;
			size++;
		}
	}

	return size;
}