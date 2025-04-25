#include <bits/stdc++.h>


class Solution {
public:
	int minGroups(std::vector<std::vector<int>>& intervals) {
		std::vector<std::pair<int, char>> cur;
		for (auto &pr: intervals)
		{
			cur.push_back({pr[0], 'a'});
			cur.push_back({pr[1], 'b'});
		}
		std::stable_sort(cur.begin(), cur.end());
		int cnt = 0;
		std::stack<std::pair<int, char>> max_pr;
		for (auto &pr: cur)
		{
			auto [val, where] = pr;
			if(max_pr.empty()) {
				max_pr.push(pr);
			} else {
				if(where == 'a') {
					max_pr.push(pr);
					cnt = std::max(cnt, (int)max_pr.size());
				} else {
					max_pr.pop();
				}
			}
		}
		if(cnt == 0)
			return 1;
		return cnt;
	}
};