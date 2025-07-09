


#include <bits/stdc++.h>


class Solution {
public:
	int maxFreeTime(int eventTime, int k, std::vector<int>& startTime, std::vector<int>& endTime) {
		int n = startTime.size();
		std::vector<int> diff;
		diff.reserve(n);
		if(startTime[0] != 0) {
			diff.push_back(startTime[0]);
		}
		for (int i = 1; i < n; i++) {
			diff.push_back(startTime[i] - endTime[i - 1]);
		}
		diff.push_back(eventTime - endTime.back());

		int res = 0, l = 0, sum = 0;
		for (int r = 0; r < diff.size(); r++) {
			sum += diff[r];
			if(r - l == k) {
				res = std::max(res, sum);
				sum -= diff[l++];
			}
		}
      res = std::max(res, sum);
		return res; 
	}
};