#include <bits/stdc++.h>



class Solution {
	int diametr(std::vector<std::vector<int>> &graf, int size) {
		std::vector<int> dist(size, -1);
		int st = 0;
		dist[st] = 0;
		std::queue<int> q;
		q.push(st);
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			for(auto next: graf[cur]) {
				if(dist[next] == -1) {
					dist[next] = dist[cur] + 1;
					q.push(next);
				}
			}
		}
		int maxs = 0;
		for (int i = 0; i < size; i++) 
		{
			if(maxs < dist[i]) {
				maxs = dist[i];
				st = i;
			} 
		}
		dist.assign(size, -1);
		dist[st] = 0;
		q.push(st);
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			for(auto next: graf[cur]) {
				if(dist[next] == -1) {
					dist[next] = dist[cur] + 1;
					q.push(next);
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			maxs = std ::max(maxs, dist[i]);
		}
		return maxs;
	}
public:
	int minimumDiameterAfterMerge(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2) {
		int n = edges1.size() + 1, m = edges2.size() + 1;
		std::vector<std::vector<int>> graf(n);
		for (auto &k: edges1)
		{
			int a = k[0], b = k[1];
			graf[a].push_back(b);
			graf[b].push_back(a);
		}

		int d1 = diametr(graf, n);

		graf.clear();
		graf.resize(m);
		for (auto &k: edges2)
		{
			int a = k[0], b = k[1];
			graf[a].push_back(b);
			graf[b].push_back(a);
		}

		int d2 = diametr(graf, m);

		return std::max({d2, d1, 1 + (d1 +1) / 2 + (d2 + 1) /2});
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<int>> edges1 {
    {0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}
};
std::vector<std::vector<int>> edges2 {
    {0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}
};
ans.minimumDiameterAfterMerge(edges1, edges2);
}