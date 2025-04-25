
#include <bits/stdc++.h>


class Solution {
	bool can(int k, int n, std::vector<int>& quantities) {
		int res = 0;
		for (auto &&i : quantities)
		{
			res += (i + k - 1) / k;
		}
		return res <= n;
	}
public:
	int minimizedMaximum(int n, std::vector<int>& quantities) {
		long long r = *std::max_element(quantities.begin(), quantities.end());
		int res = 0;
		int l = 1;
		while(l <= r) {
			long long mid = (r + l) / 2;
			if(can(mid, n, quantities)) {
				res = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return res;
	}
};