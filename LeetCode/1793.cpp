#include <bits/stdc++.h>


class Solution {
public:
	int maximumScore(std::vector<int>& nums, int k) {
		int res = nums[k];
		int cur_min = nums[k];
		int l = k, r = k;
		while(true) {
			bool can = false;
			if(l > 0 && r < (int)nums.size() - 1) {
				can = true;
				if(nums[l - 1] > nums[r + 1]) {
					cur_min = std::min(cur_min, nums[--l]);
				} else {
					cur_min = std::min(cur_min, nums[++r]);
				}
			} else if(l > 0) {
				can = true;
				cur_min = std::min(cur_min, nums[--l]);
			} else if(r < nums.size() - 1) {
				can = true;
				cur_min = std::min(cur_min, nums[++r]);
			} 
			if(!can) break;
			int score = (r - l + 1) * cur_min;
			res = std::max(res, score);
		}
		return res;
	}
};


int main() {
	Solution ans;
	std::vector<int> ss{1, 4, 3, 7, 4, 5};
	ans.maximumScore(ss, 3);
}