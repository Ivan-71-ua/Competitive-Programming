#include <bits/stdc++.h>

const int N = 500050;
const int INF = 1e9 + 100;
long long sol = 0, k, ans = 0;

class CentroidDecomposition {
public:
	std::vector<std::vector<int>> cd, &e;
	std::vector<bool> tocheck;
	std::vector<int> size, parent, cnt;
	int root;

	CentroidDecomposition(std::vector<std::vector<int>> &tree) : e(tree) {
		int sz = e.size();
		tocheck.assign(sz, true);
		cd.assign(sz, std::vector<int>());
		parent.assign(sz, -1);
		cnt.assign(N, 0);
		size.assign(sz, 0);
		dfs(0);
		root = decompose(0, sz, -1);
	}

private:
	void dfs(int u) {
		for (int v : e[u]) {
			if (v == parent[u]) continue;
			parent[v] = u;
			dfs(v);
			size[u] += 1 + size[v];
		}
	}

	void dfs2(int u, int p, int val, bool flag) {
		if (flag)
			cnt[val]++;
		else
			cnt[val]--;
		for (int v : e[u]) {
			if (tocheck[v] && v != p) {
				dfs2(v, u, val + 1, flag);
			}
		}
	}

	void solve(int u, int p, int val) {
		if (val > k) return;
		sol += cnt[k - val];
		for (int v : e[u]) {
			if (tocheck[v] && v != p) {
				solve(v, u, val + 1);
			}
		}
	}

	int decompose(int _u, int sz, int par) {
		int u = _u;
		while (true) {
			int nu = -1;
			for (int v : e[u]) {
					if (!tocheck[v] || v == parent[u]) continue;
					if (1 + size[v] > sz / 2) nu = v;
			}
			if (sz - 1 - size[u] > sz / 2 && parent[u] != -1 && tocheck[parent[u]]) nu = parent[u];
			if (nu != -1) u = nu;
			else break;
		}
		for (int v = parent[u]; v != -1 && tocheck[v]; v = parent[v]) {
			size[v] -= 1 + size[u];
		}
		sol = 0;
		dfs2(u, par, 0, true);
		sol += cnt[k];
		for (int x : e[u]) {
			if (tocheck[x]) {
					dfs2(x, u, 1, false);
					solve(x, u, 1);
					dfs2(x, u, 1, true);
			}
		}
		ans += sol / 2;
		dfs2(u, par, 0, false);
		tocheck[u] = false;
		for (int v : e[u]) {
			if (!tocheck[v]) continue;
			int V2 = 1 + size[v];
			if (v == parent[u]) V2 = sz - 1 - size[u];
			cd[u].push_back(decompose(v, V2, u));
		}
		return u;
	}
};

int main() {
	int n;
	std::cin >> n >> k;
	std::vector<std::vector<int>> tree(n, std::vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		std::cin >> a >> b;
		a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	CentroidDecomposition cd(tree);
	std::cout << ans << '\n';
	return 0;
}
