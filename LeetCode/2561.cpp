
#include <bits/stdc++.h>


class Solution {
public:
	long long minCost(std::vector<int>& basket1, std::vector<int>& basket2) {
		int res = 0, min_e = INT32_MAX, n = basket1.size();
		std::unordered_map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			cnt[basket1[i]]++;
			cnt[basket2[i]]--;
			min_e = std::min({min_e, basket1[i], basket2[i]});
		}

		std::vector<int> swap_need;
		swap_need.reserve(n);
		for(auto [v, f]: cnt) {
			if(f % 2 != 0) {
				return -1;
			}
			int diff = abs(f / 2);
			for (int i = 0; i < diff; i++) {
				swap_need.push_back(v);
			}
		}
		std::sort(swap_need.begin(), swap_need.end());
		for (int i = 0; i < swap_need.size() / 2; i++) {
			res += std::min(swap_need[i], 2 * min_e);
		}
		return res;
	}
};