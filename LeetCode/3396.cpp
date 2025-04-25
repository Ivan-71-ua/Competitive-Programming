
#include <bits/stdc++.h>




class Solution {
	bool can(std::vector<int> &num) {
		for(int i : num) {
			if(i > 1) {
				return false;
			}
		}
		return true;
	}
public:
	int minimumOperations(std::vector<int>& nums) {
		std::vector<int> sets(101, 0);
		for (int i = 0; i < nums.size(); i++) {
			sets[nums[i]]++;
		}
		int cnt = 0;
		int id = 0;
		while(!can(sets)) {
			for (int i = id; i < std::min((int)sets.size(), id + 3); i++) {
				sets[nums[i]]--;
			}
			id += 3;
		}
		return cnt;
	}
};