
#include <bits/stdc++.h>





class Solution {
	bool can(std::vector<int>& ranks, int cars, long long mid) {
		long long cnt = 0;
		for (int i = 0; i < ranks.size(); i++) {
			cnt += (long long)sqrt(mid / ranks[i]);
			if(cnt >= cars)
				break;
		}
		return cnt >= cars;
	}
public:
	long long repairCars(std::vector<int>& ranks, int cars) {
		int max = *std::max_element(ranks.begin(), ranks.end());
		int l = 1, r = cars * max * max;
		while(l <= r) {
			long long mid = (r - l) / 2 + l;
			if(can(ranks, cars, mid)) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}
};