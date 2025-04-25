
#include <bits/stdc++.h>


class Solution {
public:
	int minimumIndex(std::vector<int>& nums) {
		int cnt = 0, val = -1;
		std::unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); i++) {
			mp[nums[i]]++;
			if(mp[nums[i]] > cnt) {
				cnt = mp[nums[i]];
				val = nums[i];
			} 
		}
		int new_cnt = 0;
		for (int i = 0; i < nums.size(); i++) {
			if(nums[i] == val) {
				new_cnt++;
				cnt--;
			}
			if(new_cnt > (i +1) / 2 && cnt > (nums.size() - i - 1) / 2) {
				return i;
			}
		}
		return -1;
	}
};




