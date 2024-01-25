#include <iostream>
#include <string>
#include <unordered_map>

// Status: Accepted

using namespace std;

bool closeStrings(string word1, string word2);

int main() {
	string word1 = "cabbba";
	string word2 = "abbccc";
	bool res = closeStrings(word1, word2);
	cout << res;
}

bool closeStrings(string word1, string word2) {

	if (word1.length() != word2.length()) {
		return false;
	}

	unordered_map<char, int> map1;
	unordered_map<char, int> map2;
	unordered_map<int, int> map3;
	unordered_map<int, int> map4;

	for (size_t i = 0; i < word1.size(); i++) {
		auto iter = map1.find(word1[i]);
		if (iter == map1.end()) {
			map1.insert_or_assign(word1[i], 1);
		}
		else {
			map1.insert_or_assign(word1[i], (*iter).second + 1);
		}
	}

	for (size_t i = 0; i < word2.size(); i++) {
		auto iter = map2.find(word2[i]);
		if (iter == map2.end()) {
			map2.insert_or_assign(word2[i], 1);
		}
		else {
			map2.insert_or_assign(word2[i], (*iter).second + 1);
		}
	}

	for (auto i = map1.begin(); i != map1.end(); i++) {
		auto iter = map3.find((*i).second);
		if (iter == map3.end()) {
			map3.insert_or_assign((*i).second, 1);
		}
		else {
			map3.insert_or_assign((*i).second, (*iter).second + 1);
		}
	}

	for (auto i = map2.begin(); i != map2.end(); i++) {
		auto iter = map4.find((*i).second);
		if (iter == map4.end()) {
			map4.insert_or_assign((*i).second, 1);
		}
		else {
			map4.insert_or_assign((*i).second, (*iter).second + 1);
		}
	}

	for (auto pair : map1) {
		if (map2.find(pair.first) == map2.end())
			return false;
	}

	for (auto pair : map2) {
		if (map1.find(pair.first) == map1.end())
			return false;
	}

	for (auto pair : map4) {
		auto iter = map3.find(pair.first);
		if (iter == map3.end() || (*iter).second != pair.second) {
			return false;
		}
	}

	return true;
}