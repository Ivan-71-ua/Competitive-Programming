#include <bits/stdc++.h>

class Solution {
public:
	int largestSumAfterKNegations(std::vector<int>& nums, int k) {
		std::priority_queue<int, std::vector<int>, std::greater<int>> q;
		for (auto num: nums)
		{
			q.push(num);
		}
		while(k--) {
			int t = q.top();
			q.pop();
			q.push(-t);
		}
		int sum = 0;
		while(!q.empty()) {
			sum += q.top();
			q.pop();
		}
		return sum;
	}
};