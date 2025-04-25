#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& first, std::vector<std::vector<int>>& second) {
		if (first.size() > second.size()) std::swap(first, second);
		std::vector<std::vector<int>> res;

		int i = 0, j = 0;
		while(i < first.size() && j < second.size()) {
			int start = std::max(first[i][0], second[j][0]);
			int end = std::min(first[i][1], second[j][1]);
			if(start <= end) {
				res.push_back({start, end});
			}
			if(first[i][1] < second[j][1]) {
				i++;
			} else {
				j++;
			}
		}
		return res;
	}
};