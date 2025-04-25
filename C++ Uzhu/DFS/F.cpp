#include <bits/stdc++.h>

void DFS(int k, int cur, std::vector<std::vector<int>> &v, std::vector<bool> &used, std::vector<std::pair<int, int>> &res) {
	used[k] = true;
	for (auto now: v[k])
	{
		if(now != k) {
			if(!used[now]) {
				res.push_back(std::make_pair(k, now));
				DFS(now, k, v, used, res);
			} 
		}
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n + 1);
	std::vector<bool> used(n + 1);
	std::vector<std::pair<int, int>> res;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	DFS(1, -1, v, used, res);
	for (int i = 0; i < res.size(); i++)
	{
		std::cout << res[i].first << ' ' << res[i].second << '\n';
	}
	
}