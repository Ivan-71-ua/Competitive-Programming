#include <bits/stdc++.h>


class Solution {
	void doublet(int st,int clr, bool &ans, std::vector<std::vector<int>> &graf, std::vector<int> &color, std::vector<int> &componets) {
		if(ans)
			return;
		componets.push_back(st);
		color[st] = clr;
		for(auto &next : graf[st]) {
			if(!color[next]) {
				doublet(next, -clr, ans, graf, color, componets);
			} else if(color[next] != -clr) {
				ans = true;
			}
		}
	}
	int bfs(std::vector<int> &componet, std::vector<std::vector<int>> &graf) {
		int n = graf.size();
		int max = -1;
		for (auto &st: componet) {
			std::vector<int> dist(n, -1);
			std::queue<int> q;
			q.push(st);
			dist[st] = 0;
			
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				max = std::max(max, dist[cur]);
				for(auto nx: graf[cur]) {
					if(dist[nx] == -1) {
						q.push(nx);
						dist[nx] = dist[cur] + 1;
					}
				}
			}
		}

		return max + 1;
	}
public:
	int magnificentSets(int n, std::vector<std::vector<int>>& edges) {
		std::vector<std::vector<int>> graf(n);
		for(auto &k : edges) {
			int a = k[0] - 1, b = k[1] - 1;
			graf[a].push_back(b);
			graf[b].push_back(a);
		}
		std::vector<std::vector<int>> componets;
		std::vector<int> color(n);
		for (int i = 0; i < n; i++) {
			if(!color[i]) {
				bool ans = false;
				componets.push_back({});
				doublet(i, 1, ans, graf, color, componets.back());
				if(ans)
					return -1;
			}
		}
		int res = 0;
		for (auto &k: componets)
		{
			res += bfs(k, graf);
		}
		return res;
	}
};