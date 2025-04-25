#include <bits/stdc++.h>

const int MAX_N = 200005;
const int INF = 1e9 + 100;
using pii = std::pair<int, int>;

std::vector<std::vector<pii>> tree(MAX_N); 
std::vector<bool> isCentroidProcessed(MAX_N);
std::vector<int> subtreeSize(MAX_N);
int result = INF;
int l;

void calculateSubtreeSizes(int node, int parent) {
	subtreeSize[node] = 1;
	for (auto [neighbor, weight] : tree[node]) {
		if (neighbor != parent && !isCentroidProcessed[neighbor]) {
			calculateSubtreeSizes(neighbor, node);
			subtreeSize[node] += subtreeSize[neighbor];
		}
	}
}

int findCentroid(int node, int parent, int totalSize) {
	for (auto [neighbor, weight] : tree[node]) {
		if (neighbor != parent && !isCentroidProcessed[neighbor] && subtreeSize[neighbor] > totalSize / 2) {
			return findCentroid(neighbor, node, totalSize);
		}
	}
	return node;
}

void collectDistances(int node, int parent, int currentLength, int currentDepth, std::vector<pii> &distances) {
	if (currentLength > l) return;
	distances.emplace_back(currentLength, currentDepth);
	for (auto [neighbor, weight] : tree[node]) {
		if (neighbor != parent && !isCentroidProcessed[neighbor]) {
			collectDistances(neighbor, node, currentLength + weight, currentDepth + 1, distances);
		}
	}
}

void processCentroid(int node) {
	std::vector<pii> allDistances = {{0, 0}}; 
	isCentroidProcessed[node] = true;

	for (auto [neighbor, weight] : tree[node]) {
		if (!isCentroidProcessed[neighbor]) {
			std::vector<pii> distances;
			collectDistances(neighbor, node, weight, 1, distances);

			for (auto [dist, depth] : distances) {
					if (dist == l) {
						result = std::min(result, depth);
					}
			}

			std::unordered_map<int, int> seenDistances;
			for (auto [dist, depth] : allDistances) {
					if (dist <= l) {
						seenDistances[dist] = depth;
					}
			}

			for (auto [dist1, depth1] : distances) {
				if (seenDistances.count(l - dist1)) {
					result = std::min(result, depth1 + seenDistances[l - dist1]);
				}
			}

			allDistances.insert(allDistances.end(), distances.begin(), distances.end());
		}
	}
}

void decomposeTree(int node) {
	calculateSubtreeSizes(node, -1);
	int totalSize = subtreeSize[node];
	int centroid = findCentroid(node, -1, totalSize);

	processCentroid(centroid);

	for (auto [neighbor, weight] : tree[centroid]) {
		if (!isCentroidProcessed[neighbor]) {
			decomposeTree(neighbor);
		}
	}
}

int main() {
	int n;
	std::cin >> n >> l;

	for (int i = 0; i < n - 1; i++) {
		int u, v, t;
		std::cin >> u >> v >> t;
		u--; v--;
		tree[u].emplace_back(v, t);
		tree[v].emplace_back(u, t);
	}

	decomposeTree(0);

	if (result == INF) {
		std::cout << -1 << std::endl;
	} else {
		std::cout << result + 1 << std::endl;
	}

	return 0;
}
