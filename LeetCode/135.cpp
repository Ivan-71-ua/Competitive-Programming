#include <bits/stdc++.h>


class Solution {
public:
	int candy(std::vector<int>& ratings) {
      int  n = ratings.size(), cnt = 0;
		std::vector<int> sum(n, 1);
		for (int i = 1; i < n; i++) {
			if (ratings[i] > ratings[i - 1]) {
				sum[i] = sum[i - 1] + 1;
			}
		}
		for (int i = n - 1; i > 0; i--) {
			if(ratings[i] < ratings[i -1]) {
				sum[i - 1] = std::max(sum[i - 1], sum[i] + 1);
			}
			cnt += sum[i - 1];
		}
		return cnt + sum[n - 1];
	}
};