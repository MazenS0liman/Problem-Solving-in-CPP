#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>

// Status: Accepted

using namespace std;

bool isValidSudoku(vector<vector<char>>& board);

//int main() {
//	vector<vector<char>> board({
//		{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
//		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//	});
//
//	bool result = isValidSudoku(board);
//	cout << result << endl;
//}

bool isValidSudoku(vector<vector<char>>& board) {
	map<int, map<int, bool>> rowMap;
	map<int, map<int, bool>> colMap;
	map<pair<int, int>, map<int, bool>> boxMap;

	for (int i = 0; i < board.size(); i++) {
		vector<char> row = board.at(i); 

		for (int j = 0; j < row.size(); j++) {
			char value = row.at(j);
			if (value == '.')
				continue;

			int val = value - '0';
			cout << "Value: " << val << endl;

			if (rowMap[i].find(val) != rowMap[i].end()) {
				return false;
			}
			else {
				rowMap[i].insert({val, true});
			}

			if (colMap[j].find(val) != colMap[j].end()) {
				return false;
			}
			else {
				colMap[j].insert({ val, true });
			}

			if (boxMap[make_pair(i / 3, j / 3)].find(val) != boxMap[make_pair(i / 3, j / 3)].end()) {
				return false;
			}
			else {
				boxMap[make_pair(i / 3, j / 3)].insert({ val, true });
			}
		}
	}

	return true;
}