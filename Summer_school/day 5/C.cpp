#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

using namespace std;

struct TwoSAT {
	int n;
	vector<vector<int>> graph, rev_graph;
	vector<int> order, comp;
	vector<bool> visited;

	TwoSAT(int vars) : n(vars * 2) {
		graph.resize(n);
		rev_graph.resize(n);
		visited.assign(n, false);
		comp.assign(n, -1);
	}

	void add_implication(int u, int v) {
		graph[u].push_back(v);
		rev_graph[v].push_back(u);
	}

	void add_clause(int u, bool is_true_u, int v, bool is_true_v) {
		int u_pos = 2 * u + (is_true_u ? 0 : 1);
		int v_pos = 2 * v + (is_true_v ? 0 : 1);
		add_implication(u_pos ^ 1, v_pos);
		add_implication(v_pos ^ 1, u_pos);
	}

	void dfs1(int v) {
		visited[v] = true;
		for (int u : graph[v])
			if (!visited[u])
					dfs1(u);
		order.push_back(v);
	}

	void dfs2(int v, int label) {
		comp[v] = label;
		for (int u : rev_graph[v])
			if (comp[u] == -1)
					dfs2(u, label);
	}

	bool solve() {
		order.clear();
		fill(visited.begin(), visited.end(), false);
		for (int i = 0; i < n; ++i)
			if (!visited[i])
					dfs1(i);

		fill(comp.begin(), comp.end(), -1);
		for (int i = n - 1, label = 0; i >= 0; --i) {
			int v = order[i];
			if (comp[v] == -1)
					dfs2(v, label++);
		}

		for (int i = 0; i < n; i += 2)
			if (comp[i] == comp[i ^ 1])
					return false;

		return true;
	}
};

int main() {
	fast

	int num_vertices, num_edges;
	cin >> num_vertices >> num_edges;

	TwoSAT twosat(num_vertices);

	for (int i = 0; i < num_edges; ++i) {
		int u, v, c;
		string op;
		cin >> u >> v >> c >> op;
		--u; --v;

		if (op == "AND") {
			if (c == 1) {
					twosat.add_clause(u, true, v, true);
			} else {
					twosat.add_clause(u, false, u, false);
					twosat.add_clause(v, false, v, false);
			}
		} else if (op == "OR") {
			if (c == 1) {
					twosat.add_clause(u, true, u, true);
					twosat.add_clause(v, true, v, true);
			} else {
					twosat.add_clause(u, false, v, false);
			}
		} else if (op == "XOR") {
			if (c == 1) {

					twosat.add_clause(u, true, v, false);
					twosat.add_clause(u, false, v, true);
			} else {
					twosat.add_clause(u, true, v, true);
					twosat.add_clause(u, false, v, false);
			}
		}
	}

	if (twosat.solve()) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}
