#include <bits/stdc++.h>





class Solution {
public:
	long long countGood(std::vector<int>& nums, int k) {
		long long res = 0;
		long long cur_p = 0;
		int j = 0;
		std::unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			cur_p += (m[nums[i]] > 0 ? m[nums[i]] : 0);
			m[nums[i]]++;
			while(cur_p >= k) {
				cur_p -= m[nums[j]] - 1;
				m[nums[j]]--;
				j++;
				
			}
			res += j;
		}
		return res;
	}
};


int main() {
	Solution s;
	std::vector<int> nums = {3,1,4,3,2,2,4};
	int k = 2;
	std::cout << s.countGood(nums, k) << std::endl; // Output: 7
	return 0;
}