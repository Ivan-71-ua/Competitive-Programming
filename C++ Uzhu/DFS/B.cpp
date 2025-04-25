#include <bits/stdc++.h>

void DFS(int k, std::vector<bool> &used, std::vector<std::vector<int>> &v, int &cur, std::vector<std::pair<int, int>> &res) {
	used[k] = true;
	res[k].first = cur;
	cur++;
	for (auto now : v[k])
	{

		if(!used[now]) {
				DFS(now, used, v, cur, res);
		}
	}
	res[k].second = cur;
	cur++;
}


int main () {
	int n, m;
	std::cin >> n >> m;
	std::vector<bool> used(n + 1);
	std::vector<std::vector<int>> v(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	std::vector<std::pair<int, int>> res(n +1);
	int k;
	int cur = 1;
	std::cin >> k;
	DFS(k, used, v, cur, res);
	for(int i = 1; i <= n; i++) {
		std::cout << res[i].first << ' ' << res[i].second;
		std::cout << std::endl;
	}

}