#include <bits/stdc++.h>



class Solution {
public:
	int shortestSubarray(std::vector<int>& nums, int k) {
		int res = INT32_MAX;
		long long sum = 0;
		std::deque<std::pair<long long, int>> q;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if(sum >= k)
				res = std::min(res, i+ 1);
			while (!q.empty() && sum - q.front().first >= k) 
			{
				auto [p, id] = q.front();
				q.pop_front();
				res = std::min(res, i - id);
			}
			while(!q.empty() && q.back().first >= sum)
				q.pop_back();
			q.push_back({sum, i});
		}
		if(res == INT32_MAX)
			return -1;
		return res;
	}
};