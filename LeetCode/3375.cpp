#include <bits/stdc++.h>






class Solution {
public:
	int minOperations(std::vector<int>& nums, int k) {
		std::vector<int> hash(101, 0);
		for (int i = 0; i < nums.size(); i++) {
			hash[nums[i]]++;
		}
		for (int i = 0; i < k; i++) {
			if(hash[i] > 0) {
				return -1;
			}
		}
		int cnt = 0;
		for (int i = k; i < 101; i++) {
			if(hash[i]) {
				cnt++;
			}
		}
		return cnt;
	}
};