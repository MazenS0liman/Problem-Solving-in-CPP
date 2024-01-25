#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Status: Accepted

using namespace std;

bool uniqueOccurrences(vector<int>& arr);

//int main() {
//	vector<int> arr = { 1,2,2,1,1,3 };
//	bool res = uniqueOccurrences(arr);
//	cout << res << endl;
//}

bool uniqueOccurrences(vector<int>& arr) {
	unordered_map<int, int> map;
	unordered_set<int> set;

	for (auto i = arr.begin(); i != arr.end(); i++) {
		auto iter = map.find(*i);
		if (iter == map.end()) {
			map.insert_or_assign(*i, 1);
		}
		else {
			cout << "(" << (*iter).first << "," << (*iter).second << ") ";
			map.insert_or_assign(*i, (*iter).second + 1);
		}
	}

	cout << endl;
	for (auto i = map.begin(); i != map.end(); i++) {
		cout << (*i).first << ", " << (*i).second << endl;
		if (set.count((*i).second)) {
			return false;
		}
		else {
			set.emplace((*i).second);
		}
	}

	return true;
}