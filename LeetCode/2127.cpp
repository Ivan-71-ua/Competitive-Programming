
#include <bits/stdc++.h>



class Solution {
	int bfs(int st, std::vector<std::vector<int>> &revers_g, std::unordered_set<int> viseted_p) {
		std::queue<std::pair<int, int>> q;
		q.push({st, 0});
		int maxd = 0;
		while(!q.empty()) {
			auto [cn, d] = q.front();
			q.pop();
			for(auto next: revers_g[cn]) {
				if(!viseted_p.count(next)) {
					viseted_p.insert(next);
					q.push({next, d + 1});
					maxd = std::max(maxd, d + 1);
				}
			}
		}
		return maxd;
	}
public:
	int maximumInvitations(std::vector<int>& favorite) {
		int n = favorite.size();
		std::vector<std::vector<int>> revers_g(n);
		for (int i = 0; i < n; i++) {
			revers_g[favorite[i]].push_back(i);
		}
		int fullcycle = 0, twocyrcle =0;
		std::vector<bool> visited(n);
		for (int i = 0; i < n; i++) {
			if(visited[i]) continue;
			std::unordered_map<int, int> visited_d;
			int cur = i;
			int dist = 0;
			while (true) {
				if(visited[cur]) break;
				visited[cur] = true;
				visited_d[cur] = dist++;
				int next = favorite[cur];
				if(visited_d.count(next)) {
					int lenght = dist - visited_d[next];
					fullcycle = std::max(fullcycle, lenght);
					if(lenght == 2) {
						std::unordered_set<int> visit_path = {cur, next};
						twocyrcle += 2 + bfs(cur, revers_g, visit_path) + bfs(next, revers_g, visit_path);
					}
					break;
				}
				cur = next;
			}
		}
		return std::max(twocyrcle, fullcycle);
	}
};


