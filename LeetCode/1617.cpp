
#include <bits/stdc++.h>

class Solution {
	std::vector<std::vector<int>> list;
	int get_diameter(int mask) {
		if((mask & (mask - 1)) == 0) 
			return 0;
		int n = list.size();
		int ans = 0;
		for (int edg = 0; edg < n; edg++)
		{
			if(mask & (1LL << edg)) {
				std::queue<int> q;
				q.push(edg);
				int tmp_mask_set = mask;
				tmp_mask_set ^= (1LL << edg);
				std::vector<int> dist(n, -1);
				dist[edg] = 0;
				int max_dist = 0;
				while(!q.empty()) {
					int node = q.front();
					q.pop();
					for (auto next: list[node])
					{
						if(tmp_mask_set  & (1LL << next)) {
							q.push(next);
							tmp_mask_set ^= (1LL << next);
							dist[next] = dist[node] + 1;
							max_dist = std::max(max_dist, dist[next]);
						}
					}
				}
				if(tmp_mask_set) 
					return 0;
				ans = std::max(ans, max_dist);
			}
		}
		return ans;
	}
public:
	std::vector<int> countSubgraphsForEachDiameter(int n, std::vector<std::vector<int>>& edges) {
		list.resize(n);
		for(auto now: edges) {
			list[now[0] -1].push_back(now[1] -1);
			list[now[1] -1].push_back(now[0] -1);
		}
		std::vector<int> ans(n - 1, 0);
		for (int mask = 0; mask < (1LL << n); mask++)
		{
			int d = get_diameter(mask);
			if(d > 0) ans[d - 1]++;
		}
		return ans;
	}
};
