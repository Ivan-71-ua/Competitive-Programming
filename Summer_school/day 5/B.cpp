#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

struct TwoSAT {
	int num_vars, cnt;
	std::vector<std::vector<int>> graph, rev_graph;
	std::vector<bool> visited;
	std::vector<int> order, component;

	void init(int vars) {
		num_vars = vars * 2;
		graph.assign(num_vars, std::vector<int>());
		rev_graph.assign(num_vars, std::vector<int>());
		visited.assign(num_vars, false);
		component.assign(num_vars, -1);
	}

	void add_edge(int u, int v) {
		graph[u].push_back(v);
		rev_graph[v].push_back(u);
	}

	void add_clause(int i, bool f, int j, bool g) {
		assert(0 <= i && i < num_vars / 2);
		assert(0 <= j && j < num_vars / 2);
		add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
		add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
	}

	void dfs1(int u) {
		visited[u] = true;
		for (int v : graph[u])
			if (!visited[v])
					dfs1(v);
		order.push_back(u);
	}

	void dfs2(int u, int c) {
		component[u] = c;
		for (int v : rev_graph[u])
			if (component[v] == -1)
					dfs2(v, c);
	}

	bool solve(std::vector<int> &result) {
		cnt = 0;
		fill(visited.begin(), visited.end(), false);
		order.clear();

		for (int i = 0; i < num_vars; i++)
			if (!visited[i])
					dfs1(i);

		fill(component.begin(), component.end(), -1);
		int group = 0;
		for (int i = num_vars - 1; i >= 0; i--) {
			int u = order[i];
			if (component[u] == -1)
					dfs2(u, group++);
		}

		for (int i = 0; i < num_vars; i += 2)
			if (component[i] == component[i + 1])
					return false;

		result.clear();
		for (int i = 0; i < num_vars; i += 2) {
			int choose = (component[i] > component[i ^ 1]) ? i : (i ^ 1);
			result.push_back(choose / 2);
		}

		return true;
	}
};

int main() {
	fast

	int num_participants, num_judges;
	while (std::cin >> num_participants >> num_judges) {
		TwoSAT twosat;
		twosat.init(num_participants);
		for (int i = 0; i < num_judges; i++) {
			int a, b;
			std::cin >> a >> b;
			twosat.add_clause(abs(a) - 1, a > 0, abs(b) - 1, b > 0);
		}
		twosat.add_clause(0, true, 0, true); 
		std::vector<int> result;
		if (twosat.solve(result))
			std::cout << "yes\n";
		else
			std::cout << "no\n";
	}

	return 0;
}
