#include <bits/stdc++.h>


class Solution {
public:
	int maxValue(std::vector<std::vector<int>>& events, int k) {
		int n = events.size();
		 sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
		for (int i = 1; i <= n; i++) {
			int prev = binarySearch(events, events[i - 1][0]);
			for (int j = 1; j <= k; j++) {
				dp[i][j] = std::max(dp[i - 1][j], dp[prev + 1][j - 1] + events[i - 1][2]);
			}
		}
		return dp[n][k];
	}
	int binarySearch(std::vector<std::vector<int>>& events, int start) {
		int res = -1, l = 0, r = events.size() - 1;
		while(l <= r) {
			int mid = l + (r - l) / 2;
			if(events[mid][1] < start) {
				res = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return res;
	}
};