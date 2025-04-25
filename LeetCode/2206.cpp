
#include <bits/stdc++.h>



class Solution {
public:
	bool divideArray(std::vector<int>& nums) {
		std::vector<int> num(500 + 2);
		for(auto k: nums) {
			num[k]++;
		}
		for (int i = 1; i <= 500; i++) {
			if(num[i] & 1) return false;
		}
		return true;
	}
};

int main() {
	Solution ans;
	std::vector<int> nums = {1, 2, 3, 4};
	std::cout << ans.divideArray(nums) << std::endl;
}