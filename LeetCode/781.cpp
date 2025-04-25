

#include <bits/stdc++.h>


class Solution {
public:
	int numRabbits(std::vector<int>& answers) {
		int res = 0;
		std::unordered_map<int, int> mp;
		for(auto i: answers) {
			mp[i]++;
		}
		for(auto [k, v]: mp) {
			res += (v + k) / (k + 1) * (k + 1);
		}
		return res;
	}
};