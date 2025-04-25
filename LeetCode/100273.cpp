#include <bits/stdc++.h>



class Solution {
public:
	long long numberOfSubarrays(std::vector<int>& nums) {
		long long res = 0;
		std::stack<std::vector<int>> s;
		for (auto c: nums) {
				while (s.size() && s.top()[0] < c) s.pop();
				if (s.size() == 0 || s.top()[0] > c) s.push({c, 0});
				res += ++s.top()[1];
		}
		return res;
	}
};