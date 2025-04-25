#include <bits/stdc++.h>

class Solution {
public:
   int maxProduct(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
	}
};


int main() {
	Solution ans;
	std::vector p{3, 4, 5, 2};
	std::cout << ans.maxProduct(p);
}