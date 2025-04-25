#include <bits/stdc++.h>
using namespace std;

struct Graph {
	int V;
	vector<vector<int>> adj;
	vector<int> color;

	Graph(int V) : V(V), adj(V), color(V, 0) {}

	void add_edge(int u, int v) {
		adj[u].push_back(v);
	}

	bool dfs(int v) {
		if (color[v] != 0) return color[v] == 1;
		color[v] = 1;
		for (int u : adj[v]) {
			if (dfs(u)) return true;
		}
		color[v] = 2;
		return false;
	}
};

int get_bit(int x, int y) {
	return (x >> y) & 1;
}

bool check(const vector<vector<int>>& a, const vector<vector<int>>& b, int k) {
	int n = a.size(), m = a[0].size();
	vector<bool> must_row(n, false), must_col(m, false);
	Graph g(n + m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int bit_a = get_bit(a[i][j], k);
			int bit_b = get_bit(b[i][j], k);

			if (bit_a != bit_b) {
				if (bit_b == 0) must_row[i] = true;
				else must_col[j] = true;
			}

			if (bit_b == 0) g.add_edge(j + n, i);
			else g.add_edge(i, j + n);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (must_row[i] && g.dfs(i)) return false;
	}
	for (int j = 0; j < m; ++j) {
		if (must_col[j] && g.dfs(j + n)) return false;
	}

	return true;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));

	for (auto& row : a) {
		for (int& x : row) cin >> x;
	}
	for (auto& row : b) {
		for (int& x : row) cin >> x;
	}

	for (int i = 0; i < 30; ++i) {
		if (!check(a, b, i)) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
