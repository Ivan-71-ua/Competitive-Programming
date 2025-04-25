#include <bits/stdc++.h>



class Solution {
public:
	long long maxKelements(std::vector<int>& nums, int k) {
		std::priority_queue<int> q;
		for (auto &n : nums)
		{
			q.push(n);
		}
		long long res = 0;
		while(k--) {
			res += q.top();
			int tmp = std::ceil(q.top() / 3.0);
			q.pop();
			q.push(tmp);
		}
		return res;
	}
};