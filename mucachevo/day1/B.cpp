#include <bits/stdc++.h>


long long totalPaths = 0;

void dfs(int v, int p, int deep, int k, 
	std::vector<std::vector<int>> &tree) {
	if (deep == k) {
		totalPaths++;
		return;
	}

	for (int next : tree[v]) {
		if (next != p) {
			dfs(next, v, deep + 1, k, tree);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	std::vector<std::vector<int>> tree(n +1);

	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		dfs(i, -1, 0, k, tree);
	}

	std::cout << totalPaths / 2 << '\n';

}
