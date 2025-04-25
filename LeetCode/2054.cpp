#include <bits/stdc++.h>


class Solution {
public:
	int maxTwoEvents(std::vector<std::vector<int>>& events) {
		std::vector<std::vector<int>> time_line;
		for (auto &&i : events)
		{
			int s = i[0];
			int f = i[1];
			int v = i[2];
			time_line.push_back({s, 1, v});
			time_line.push_back({f  + 1 , -1, v});
		}
		std::stable_sort(time_line.begin(), time_line.end());
		int max_seen =0;
		int ans = 0;
		for (auto &&i : time_line)
		{
			int t = i[0];
			int w = i[1];
			int v = i[2];
			if(w == 1) {
				ans = std::max(ans, v + max_seen);
			} else if(w == -1){
				max_seen = std::max(max_seen, v);
			}
		}
		return ans;
	}
};