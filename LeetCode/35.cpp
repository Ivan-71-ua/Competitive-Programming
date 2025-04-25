#include <bits/stdc++.h>


class Solution {
public:
	int searchInsert(std::vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while(l <= r) {
			int midl = (l + r) / 2;
			if(nums[midl] == target)
				return midl;
			if(nums[midl] > target) {
				r = midl - 1;
			} else {
				l = midl + 1;
			}
		}
		return l;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{1, 3, 4, 5,10, 11, 34, 100, 111,120, 132};
	ans.searchInsert(ss, 2);
}