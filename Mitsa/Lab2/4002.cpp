#include <bits/stdc++.h>

int flag;

void dfs(int v, std::vector<std::vector<int>> &list_edges, std::vector<int> &color) {
	for (auto next : list_edges[v]) {
		if (color[next] == 0 && flag) {
			color[next] = 3 - color[v];  
			dfs(next, list_edges, color);
		} else if (color[next] == color[v]) {
			flag = 0;  
		}
	}
}

int main() {
	int k;
	std::cin >> k;
	while (k--) {
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> list_edges(2 * n);
		std::vector<int> color(2 * n, 0);
		flag = 1; 
		
		for (int i = 0; i < n; i++) {
			int a, b;
			std::cin >> a >> b;
			list_edges[a - 1].push_back(b - 1);
			list_edges[b - 1].push_back(a - 1);
		}

		
		for (int i = 0; i < 2 * n; i++) {
			if (color[i] == 0 && flag) {
					color[i] = 1; 
					dfs(i, list_edges, color);
			}
		}

		if (!flag) {
			std::cout << "possible\n";
		} else {
			std::cout << "impossible\n";
		}
	}
}
