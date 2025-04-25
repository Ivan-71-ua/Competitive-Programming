#include <bits/stdc++.h>

class CentroidDecomposition {
private:
	const long long INF = 1e18;
	std::vector<std::vector<long long>> &tree;
	std::vector<long long> subtreeSize;
	std::vector<long long> centroidParent;
	std::vector<long long> minRedDistance;
	std::vector<bool> isCentroidProcessed;

	void calculateSubtreeSizes(long long node, long long parent) {
		subtreeSize[node] = 1;
		for (long long neighbor : tree[node]) {
			if (neighbor != parent && !isCentroidProcessed[neighbor]) {
					calculateSubtreeSizes(neighbor, node);
					subtreeSize[node] += subtreeSize[neighbor];
			}
		}
	}

	long long findCentroid(long long node, long long parent, long long totalSize) {
		for (long long neighbor : tree[node]) {
			if (neighbor != parent && !isCentroidProcessed[neighbor] && subtreeSize[neighbor] > totalSize / 2) {
					return findCentroid(neighbor, node, totalSize);
			}
		}
		return node;
	}

	void decomposeTree(long long node, long long parent) {
		calculateSubtreeSizes(node, -1);
		long long totalSize = subtreeSize[node];
		long long centroid = findCentroid(node, -1, totalSize);

		centroidParent[centroid] = parent;
		isCentroidProcessed[centroid] = true;

		for (long long neighbor : tree[centroid]) {
			if (!isCentroidProcessed[neighbor]) {
					decomposeTree(neighbor, centroid);
			}
		}
	}

	void updateRedDistance(long long node) {
		long long current = node;
		long long distance = 0;

		while (current != -1) {
			minRedDistance[current] = std::min(minRedDistance[current], distance);
			current = centroidParent[current];
			distance++;
		}
	}

	long long queryMinDistance(long long node) {
		long long current = node;
		long long distance = 0;
		long long result = INF;

		while (current != -1) {
			result = std::min(result, minRedDistance[current] + distance);
			current = centroidParent[current];
			distance++;
		}

		return result;
	}

public:
	CentroidDecomposition(std::vector<std::vector<long long>> &graph) : tree(graph) {
		long long n = tree.size();
		subtreeSize.resize(n);
		centroidParent.assign(n, -1);
		minRedDistance.assign(n, INF);
		isCentroidProcessed.assign(n, false);

		decomposeTree(0, -1);
		updateRedDistance(0); 
	}

	void processQuery(long long type, long long node) {
		if (type == 1) {
			updateRedDistance(node);
		} else if (type == 2) {
			std::cout << queryMinDistance(node) << '\n';
		}
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long n, m;
	std::cin >> n >> m;

	std::vector<std::vector<long long>> tree(n);
	for (long long i = 0; i < n - 1; i++) {
		long long a, b;
		std::cin >> a >> b;
		a--, b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	CentroidDecomposition cd(tree);

	for (long long i = 0; i < m; i++) {
		long long t, v;
		std::cin >> t >> v;
		v--;
		cd.processQuery(t, v);
	}

	return 0;
}
