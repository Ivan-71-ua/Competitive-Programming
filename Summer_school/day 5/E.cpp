#include <bits/stdc++.h>
using namespace std;

struct Query {
	int x, y, z, id;
	Query(int x, int y, int z, int id) : x(x), y(y), z(z), id(id) {}
};

int find_parent(int u, vector<int>& parent) {
	if (u != parent[u]) {
		parent[u] = find_parent(parent[u], parent);
	}
	return parent[u];
}

void union_sets(int u, int v, vector<int>& parent, vector<int>& rank, vector<int>& component_size) {
	u = find_parent(u, parent);
	v = find_parent(v, parent);
	if (u != v) {
		if (rank[u] < rank[v]) {
			swap(u, v);
		}
		parent[v] = u;
		component_size[u] += component_size[v];
		if (rank[u] == rank[v]) {
			rank[u]++;
		}
	}
}

bool can_visit(int x, int y, int z, vector<int>& parent, vector<int>& component_size) {
	int root_x = find_parent(x, parent);
	int root_y = find_parent(y, parent);
	int total_size = component_size[root_x];
	if (root_x != root_y) {
		total_size += component_size[root_y];
	}
	return total_size >= z;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges[i] = {u, v};
	}
	
	int q;
	cin >> q;
	vector<Query> queries;
	for (int i = 0; i < q; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		queries.emplace_back(x, y, z, i);
	}
	
	vector<int> results(q, -1);
	vector<int> parent(n + 1), rank(n + 1, 0), component_size(n + 1, 1);
	iota(parent.begin(), parent.end(), 0); 
	
	vector<int> last_update(m, 0);
	for (int i = 0; i < m; i++) {
		union_sets(edges[i].first, edges[i].second, parent, rank, component_size);
		last_update[i] = i;
	}
	
	for (int i = 0; i < q; i++) {
		int l = 0, r = m - 1;
		while (l < r) {
			int mid = (l + r) / 2;
			
			vector<int> parent_copy = parent;
			vector<int> component_size_copy = component_size;
			for (int j = 0; j <= mid; ++j) {
					union_sets(edges[j].first, edges[j].second, parent_copy, rank, component_size_copy);
			}
			
			if (can_visit(queries[i].x, queries[i].y, queries[i].z, parent_copy, component_size_copy)) {
					r = mid;
			} else {
					l = mid + 1;
			}
		}
		results[queries[i].id] = l + 1;
	}
	
	for (const auto& result : results) {
		cout << result << '\n';
	}
	
	return 0;
}
