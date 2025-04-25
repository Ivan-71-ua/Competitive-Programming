#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

struct Query {
	int a, b, id;
	Query(int a, int b, int id) : a(a), b(b), id(id) {}
};

struct Road {
	int u, v;
	Road(int u, int v) : u(u), v(v) {}
};

int find_parent(int u, std::vector<int>& parent) {
	if (u != parent[u]) {
		parent[u] = find_parent(parent[u], parent);
	}
	return parent[u];
}

void union_sets(int u, int v, std::vector<int>& parent, std::vector<int>& rank) {
	u = find_parent(u, parent);
	v = find_parent(v, parent);
	if (u != v) {
		if (rank[u] < rank[v]) {
			std::swap(u, v);
		}
		parent[v] = u;
		if (rank[u] == rank[v]) {
			rank[u]++;
		}
	}
}

int main() {
	fast
	int n, m, q;
	std::cin >> n >> m >> q;
	
	std::vector<Road> roads;
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		roads.push_back({u - 1, v - 1});
	}
	
	std::vector<Query> queries;
	std::vector<int> results(q, -1);
	for (int i = 0; i < q; i++) {
		int a, b;
		std::cin >> a >> b;
		if (a == b) {
			results[i] = 0; // якщо a == b, відповідь одразу 0
		} else {
			queries.push_back({a - 1, b - 1, i});
		}
	}
	
	std::vector<int> l(q, 0), r(q, m);
	bool changed = true;
	
	while (changed) {
		changed = false;
		
		std::vector<std::vector<Query>> query_buckets(m + 1);
		
		for (int i = 0; i < q; i++) {
			if (l[i] < r[i]) {
					int mid = (l[i] + r[i]) / 2;
					query_buckets[mid].push_back(queries[i]);
					changed = true;
			}
		}
		
		std::vector<int> parent(n), rank(n, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		
		for (int day = 0; day <= m; day++) {
			if (day < m) {
					union_sets(roads[day].u, roads[day].v, parent, rank);
			}
			
			for (const auto& query : query_buckets[day]) {
					if (find_parent(query.a, parent) == find_parent(query.b, parent)) {
						results[query.id] = day + 1;
						r[query.id] = day;
					} else {
						l[query.id] = day + 1;
					}
			}
		}
	}
	for (const auto& result : results) {
		std::cout << result << "\n";
	}
	return 0;
}
