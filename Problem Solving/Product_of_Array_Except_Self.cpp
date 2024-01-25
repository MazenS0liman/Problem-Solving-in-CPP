#include <iostream>
#include <vector>

using namespace std;

// Status: Accepted

vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> output(nums.size());

	int prefix = 1;
	int postfix = 1;

	for (int i = 0; i < nums.size(); i++) {
		 output[i] = prefix;
		 prefix = prefix * nums[i];
	}

	for (int i = nums.size() - 1; i >= 0; i--) {
		output[i] = output[i] * postfix;
		postfix = postfix * nums[i];
	}

	return output;
}