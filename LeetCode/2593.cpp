
#include <bits/stdc++.h>





class Solution {
public:
	long long findScore(std::vector<int>& nums) {
		std::vector<int> can(nums.size(), 1);
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
		for (int i = 0; i < nums.size(); i++)
		{
			q.push({nums[i], i});
		}
		long long res = 0;
		while(!q.empty()) {
			auto [v, i] = q.top();
			q.pop();
			if(!can[i]) continue;
			res += v;
			can[i] = can[i < nums.size() - 1 ? i + 1 : i] = can[i > 0 ? i - 1 : 0] = 0;
		}
		return res;
	}
};