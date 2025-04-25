

#include <bits/stdc++.h>


class Solution {
public:
	int minOperations(std::vector<int>& nums, int k) {
		std::priority_queue<long long ,std::vector<long long>, std::greater<>> dig;
		for (auto &k : nums)
			dig.push(k);
		int cnt = 0;
		while(dig.top() < k) {
			cnt++;
			long long a = dig.top();
			dig.pop();
			long long b = dig.top();
			dig.pop();

			dig.push(std::min(a, b) * 2 + std::max(a, b));
		}
		return cnt;
	}
};