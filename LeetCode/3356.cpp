#include <bits/stdc++.h>


class Solution {
public:
	int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
		int pos = 0, sum = 0, n = nums.size();
		std::vector<int> diffarr(n + 1);
		for (int i = 0; i < n; i++) {
			while(sum + diffarr[i] < nums[i]) {
				if(pos == queries.size())
					return -1;
				int start = queries[pos][0], end = queries[pos][1], val = queries[pos][2];
				pos++;
				if(end < i) continue;
				diffarr[std::max(start, i)] += val;
				diffarr[end + 1] -= val;
			}
			sum += diffarr[i];
		}
		return pos;
	}
};