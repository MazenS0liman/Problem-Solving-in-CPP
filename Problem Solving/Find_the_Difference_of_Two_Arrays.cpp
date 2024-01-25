#include <iostream>
#include <vector>
#include <unordered_set>

// Status: Accepted

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> set1;
	unordered_set<int> set2;
	unordered_set<int> set3;
	unordered_set<int> set4;
	vector<vector<int>> res;
	vector<int> vec1;
	vector<int> vec2;

	for (auto i = nums1.begin(); i != nums1.end(); i++) {
		set1.emplace(*i);
	}

	for (auto i = nums2.begin(); i != nums2.end(); i++) {
		set2.emplace(*i);
		if (!set1.count(*i) && !set4.count(*i)) {
			vec2.push_back(*i);
			set4.emplace(*i);
		}
	}

	for (auto i = nums1.begin(); i != nums1.end(); i++) {
		if (!set2.count(*i) && !set3.count(*i)) {
			vec1.push_back(*i);
			set3.emplace(*i);
		}
	}

	res.push_back(vec1);
	res.push_back(vec2);
	return res;
}