#include <iostream>
#include <vector>

// Status: Accepted

using namespace std;

void moveZeroes(vector<int>&);

//int main() {
//	vector<int> nums = {0, 1, 0, 3, 12};
//	moveZeroes(nums);
//	for (auto i = nums.begin(); i != nums.end(); i++) {
//		cout << *i << " ";
//	}
//}

void moveZeroes(vector<int>& nums) {
	auto j = nums.begin();

	for (auto i = nums.begin(); i != nums.end(); i++) {
		if (i != j && *i != 0) {
			if (*j != 0)
				continue;
			else {
				auto tmp = *j;
				*j = *i;
				*i = tmp;
				j++;
			}
		}
		else if (*i == 0 && *j != 0) {
			j = i;
		}
	}
}