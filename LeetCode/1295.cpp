#include <bits/stdc++.h>


class Solution {
public:
	int findNumbers(std::vector<int>& nums) {
		int res = 0;
		for(auto i: nums) {
			int cnt = 0;
			while(i) {
				i /= 10;
				cnt++;
			}
			if(cnt & 1) {
				res++;
			}
		}
		return res;
	}
};