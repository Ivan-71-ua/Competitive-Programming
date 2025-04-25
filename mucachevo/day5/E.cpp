#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e5 + 5;

vector<int> tree[MAXN];    
int subtree_size[MAXN];    
int parent[MAXN];          
int level[MAXN];           
set<int> black_nodes;      

void sub_sizes(int v, int p) {
	subtree_size[v] = 1;
	for (int u : tree[v]) {
		if (u == p) continue;
		sub_sizes(u, v);
		subtree_size[v] += subtree_size[u];
	}
}

int centroid_decomposition(int v, int p, int total_size) {
	for (int u : tree[v]) {
		if (u != p && subtree_size[u] > total_size / 2) {
			return centroid_decomposition(u, v, total_size);
		}
	}
	parent[v] = p;
	for (int u : tree[v]) {
		if (u != p) {
			int sub_centroid = centroid_decomposition(u, v, subtree_size[u]);
		}
	}
	return v;
}

int find_nearest_black(int v) {
	if (black_nodes.empty()) return -1;
	queue<pair<int, int>> q;
	set<int> visited;
	q.push({v, 0});
	visited.insert(v);

	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (black_nodes.count(cur)) {
			return dist;
		}

		for (int u : tree[cur]) {
			if (!visited.count(u)) {
					visited.insert(u);
					q.push({u, dist + 1});
			}
		}
	}
	return -1;
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		tree[i].clear();
		parent[i] = -1;
	}
	black_nodes.clear();

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	sub_sizes(1, -1);
	centroid_decomposition(1, -1, subtree_size[1]);

	for (int i = 0; i < m; i++) {
		int type, v;
		cin >> type >> v;

		if (type == 1) {
			black_nodes.insert(v); 
		} else if (type == 2) {
			cout << find_nearest_black(v) << ' '; 
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
