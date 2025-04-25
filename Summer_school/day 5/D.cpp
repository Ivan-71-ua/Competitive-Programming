#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

class TwoSAT {
public:
	int n;
	vector<vector<int>> graph, rev_graph;
	vector<int> order, comp;
	vector<bool> visited;
	vector<int> assignment;

	TwoSAT(int vars) : n(vars * 2) {
		graph.resize(n);
		rev_graph.resize(n);
		visited.assign(n, false);
		comp.assign(n, -1);
		assignment.assign(vars, -1);
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
		for (int i = 0; i < n; i++)
			if (!visited[i])
					dfs1(i);

		fill(comp.begin(), comp.end(), -1);
		for (int i = n - 1, label = 0; i >= 0; i--) {
			int v = order[i];
			if (comp[v] == -1)
					dfs2(v, label++);
		}

		for (int i = 0; i < n; i += 2) {
			if (comp[i] == comp[i ^ 1])
					return false;
			assignment[i / 2] = comp[i] > comp[i ^ 1];
		}

		return true;
	}

	vector<int> get_solution() {
		vector<int> solution;
		for (int i = 0; i < assignment.size(); i++)
			if (assignment[i])
					solution.push_back(i + 1);
		return solution;
	}
};

int main() {
	fast;

	int n, m;
	cin >> n >> m;

	TwoSAT twosat(n * 2);

	vector<pair<int, int>> matches(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		matches[i] = {a, b};
		twosat.add_clause(a - 1, true, b - 1, true); 
		twosat.add_clause(a - 1, false, b - 1, false); 
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		twosat.add_clause(u - 1, false, v - 1, false); 
	}

	if (twosat.solve()) {
		vector<int> solution = twosat.get_solution();
		for (int s : solution)
			cout << s << " ";
		cout << "\n";
	} else {
		cout << "-1\n";
	}

	return 0;
}
