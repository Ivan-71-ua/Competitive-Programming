
#include <bits/stdc++.h>





class Solution {
public:
	int countPaths(int n, std::vector<std::vector<int>>& roads) {
		std::vector<std::vector<std::pair<int, int>>> graph_w_n(n);
		for (int i = 0; i < roads.size(); i++) {
			graph_w_n[roads[i][0]].push_back({roads[i][1], roads[i][2]});
			graph_w_n[roads[i][1]].push_back({roads[i][0], roads[i][2]});
		}
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
		std::vector<long long> dist(n, LLONG_MAX);
		std::vector<long long> cnt_ways(n, 0);
		cnt_ways[0] = 1;
		dist[0] = 0;
		pq.push({0, 0});
		while(!pq.empty()) {
			auto [d, v] = pq.top();
			pq.pop();
			for(auto [to, w]: graph_w_n[v]) {
				if(dist[to] > d + w) {
					dist[to] = d + w;
					cnt_ways[to] = cnt_ways[v];
					pq.push({dist[to], to});
				} else if(dist[to] == d + w) {
					cnt_ways[to] = (cnt_ways[to] + cnt_ways[v]) % 1000000007;
				}
			}
		}
		return cnt_ways[n - 1];
	}
};

int main() {
	std::vector<std::vector<int>> roads{{1,0,10}};
	Solution s;
	std::cout << s.countPaths(2, roads) << '\n';
}