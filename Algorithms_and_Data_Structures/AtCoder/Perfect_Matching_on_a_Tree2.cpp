#include <bits/stdc++.h>


void dfs_size(const std::vector<std::vector<int>>& tree, int node, int parent, std::vector<int>& size) {
	size[node] = 1;
	for (int neighbor : tree[node]) {
		if (neighbor != parent) {
			dfs_size(tree, neighbor, node, size);
			size[node] += size[neighbor];
		}
	}
}

int dfs_centroid(const std::vector<std::vector<int>>& tree, int node, int parent, const std::vector<int>& size, int N) {
	for (int neighbor : tree[node]) {
		if (neighbor != parent && size[neighbor] > N / 2) {
			return dfs_centroid(tree, neighbor, node, size, N);
		}
	}
	return node;
}

int find_centroid(const std::vector<std::vector<int>>& tree, int N) {
	std::vector<int> size(N + 1);
	dfs_size(tree, 1, -1, size);
	return dfs_centroid(tree, 1, -1, size, N);
}

void DFS_collect_nodes(const std::vector<std::vector<int>>& tree, int start, std::vector<int>& result, const std::vector<bool>& excluded) {
	std::stack<int> s;
	std::vector<bool> visited(tree.size(), false);
	s.push(start);

	while (!s.empty()) {
		int node = s.top();
		s.pop();

		if (visited[node]) continue;
		visited[node] = true;
		result.push_back(node);

		for (int neighbor : tree[node]) {
			if (!visited[neighbor] && !excluded[neighbor]) {
				s.push(neighbor);
			}
		}
	}
}

int main() {
	int N;
	std::cin >> N;
	std::vector<std::vector<int>> tree(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		std::cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	int centroid = find_centroid(tree, N);
	std::vector<bool> excluded(N + 1, false);
	excluded[centroid] = true;

	std::vector<int> sub_ver;
	for (int neighbor : tree[centroid]) {
		DFS_collect_nodes(tree, neighbor, sub_ver, excluded);
	}

	if (sub_ver.size() % 2 != 0) {
		sub_ver.push_back(centroid);
	}

	for (int i = 0; i < sub_ver.size() / 2; i++) {
		std::cout << sub_ver[i] << " " << sub_ver[i + sub_ver.size() / 2] << '\n';
	}

	return 0;
}
