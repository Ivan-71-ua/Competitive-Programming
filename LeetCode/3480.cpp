#include <bits/stdc++.h>

class Solution {
public:
	long long maxSubarrays(int n, std::vector<std::vector<int>>& conpr) {
		std::vector<std::vector<int>> left(n + 1, std::vector<int>(2, 0));
		for(auto &pair: conpr) {
			int a = std::min(pair[0], pair[1]), b = std::max(pair[0], pair[1]);
			if(left[b][0] < a) {
				left[b][1] = left[b][0];
				left[b][0] = a;
			} else if(left[b][1] < a) {
				left[b][1] = a;
			}
		}
		long long res = 0;
		int top1 = 0, top2 = 0;
		long long max_bs = 0;
		std::vector<long long> bonus(n + 1);
		for (int i = 1; i <= n; i++) {
			for(auto a: left[i]) {
				if(a > top1) {
					top2 = top1;
					top1 = a;
				} else if(top2 < a) {
					top2 = a;
				}
			}
			res += i - top1;
			if(top1) {
				bonus[top1] += top1 - top2;
				max_bs = std::max(bonus[top1], max_bs);
			} 
		}
		
		return res + max_bs;
	}
};
