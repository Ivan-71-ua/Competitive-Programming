
#include <bits/stdc++.h>

class Solution {
public:
	int findLucky(std::vector<int>& arr) {
		std::vector<int> cnt(501);
		int res = -1;
		for(auto n: arr) {
			cnt[n]++;
		}
		for (int i = 0; i < 501; i++) {
			if(cnt[i] && cnt[i] == i) {
				res = i;
			}
		}
		return res;
	}
};