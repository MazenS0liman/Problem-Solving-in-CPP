#include <iostream>
#include <string>

// Status: Accepted

using namespace std;

string mergeAlternately(string word1, string word2) {
	string result = "";

	size_t i = 0;
	size_t j = 0;

	while (i < word1.size() && j < word2.size()) {
		result += string(1, word1.at(i)) + string(1, word2.at(j));
		i++;
		j++;
	}

	while (i < word1.size()) {
		result += word1.at(i);
		i++;
	}

	while (j < word2.size()) {
		result += word2.at(j);
		j++;
	}

	return result;
}