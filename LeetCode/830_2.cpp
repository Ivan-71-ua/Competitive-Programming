#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::vector<int>> largeGroupPositions(std::string s) {
		std::vector<std::vector<int>> ans;
		int start = 0, n = s.length(), end;
		for (end = 0; end < n; ++end) {
			if (s[end] != s[start]) {
				if (end-start >= 3) {
					ans.push_back({start, end-1});
				}
				start = end;
			}
		}
		if (end-start >= 3) {
			ans.push_back({start, end-1});
		}
		return ans;
	}
};