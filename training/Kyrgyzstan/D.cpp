#include <bits/stdc++.h>
 
 
void dfs(int v, int cur_c, int &flag, std::vector<std::vector<int>> &list, std::vector<int> &color) {
	if (flag) return;
	color[v] = cur_c;
	for (auto n: list[v]) {
		if (!color[n]) {
			dfs(n, 3 - cur_c, flag, list, color);
		} else if (color[v] == color[n]) {
			flag = 1;
		}
	}
}
 
int main() {
	int k;
	std::cin >> k;
	while (k--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<int>> list(n + 1);
		std::vector<int> color(n + 1, 0);
		
		for (int i = 0; i < m; i++) {
			int a, b;
			std::cin >> a >> b;
			list[a].push_back(b);
			list[b].push_back(a);
		}
 
		int flag = 0;
		
		for (int i = 1; i <= n; i++) {
			if (!color[i]) {
					dfs(i, 1, flag, list, color);
			}
			if (flag) break;
		}
 
		if (!flag) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
	return 0;
}