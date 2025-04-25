#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<bool> isCentroidProcessed;
vector<int> subtreeSize;
long long result = 0;
int k1, k2;

void calculateSubtreeSizes(int node, int parent) {
	subtreeSize[node] = 1;
	for (int neighbor : tree[node]) {
		if (neighbor != parent && !isCentroidProcessed[neighbor]) {
			calculateSubtreeSizes(neighbor, node);
			subtreeSize[node] += subtreeSize[neighbor];
		}
	}
}

int findCentroid(int node, int parent, int totalSize) {
	for (int neighbor : tree[node]) {
		if (neighbor != parent && !isCentroidProcessed[neighbor] && subtreeSize[neighbor] > totalSize / 2) {
			return findCentroid(neighbor, node, totalSize);
		}
	}
	return node;
}

void collectDistances(int node, int parent, int depth, vector<int> &distances) {
	if (depth > k2) return;
	distances.push_back(depth);
	for (int neighbor : tree[node]) {
		if (neighbor != parent && !isCentroidProcessed[neighbor]) {
			collectDistances(neighbor, node, depth + 1, distances);
		}
	}
}

void countPaths(const vector<int> &distances, unordered_map<int, int> &prefixSum) {
	for (int depth : distances) {
		if (depth >= k1 && depth <= k2) {
			result++; 
		}
		for (int d = k1 - depth; d <= k2 - depth; ++d) {
			if (prefixSum.count(d)) {
					result += prefixSum[d]; 
			}
		}
	}
}

void processCentroid(int node) {
	isCentroidProcessed[node] = true;
	unordered_map<int, int> prefixSum;

	for (int neighbor : tree[node]) {
		if (!isCentroidProcessed[neighbor]) {
			vector<int> distances;
			collectDistances(neighbor, node, 1, distances);

			countPaths(distances, prefixSum);

			for (int depth : distances) {
					prefixSum[depth]++;
			}
		}
	}
}

void decomposeTree(int node) {
	calculateSubtreeSizes(node, -1);
	int totalSize = subtreeSize[node];
	int centroid = findCentroid(node, -1, totalSize);

	processCentroid(centroid);

	for (int neighbor : tree[centroid]) {
		if (!isCentroidProcessed[neighbor]) {
			decomposeTree(neighbor);
		}
	}
}

int main() {
	int n;
	cin >> n >> k1 >> k2;

	tree.resize(n);
	isCentroidProcessed.assign(n, false);
	subtreeSize.assign(n, 0);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a - 1].push_back(b - 1);
		tree[b - 1].push_back(a - 1);
	}

	decomposeTree(0);

	cout << result << endl;

	return 0;
}
