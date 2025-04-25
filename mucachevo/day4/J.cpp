#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct VectorHash {
	size_t operator()(const vector<int>& vec) const {
		size_t seed = vec.size();
		for (auto& i : vec) {
			seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}
};

int lastIndex;
unordered_map<vector<int>, int, VectorHash> hashTable;
unordered_map<int, bool> isSymmetric;

int computeTreeHash(int node, int parent, const vector<vector<int>>& tree) {
	vector<int> childHashes;
	for (int neighbor : tree[node]) {
		if (neighbor != parent) {
			childHashes.push_back(computeTreeHash(neighbor, node, tree));
		}
	}

	sort(childHashes.begin(), childHashes.end());

	if (!hashTable.count(childHashes)) {
		unordered_map<int, int> frequency;
		for (int hash : childHashes) {
			frequency[hash]++;
		}

		int oddCount = 0, invalidCount = 0;
		for (auto& [hash, freq] : frequency) {
			if (freq % 2 == 1) {
					oddCount++;
					invalidCount += !isSymmetric[hash];
			}
		}

		hashTable[childHashes] = lastIndex;
		isSymmetric[lastIndex] = (oddCount < 2) && (invalidCount == 0);
		lastIndex++;
	}

	return hashTable[childHashes];
}

void processTestCase() {
	int n;
	cin >> n;

	vector<vector<int>> tree(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	hashTable.clear();
	isSymmetric.clear();
	hashTable[{}] = 0;
	isSymmetric[0] = true;
	lastIndex = 1;

	int rootHash = computeTreeHash(0, -1, tree);
	cout << (isSymmetric[rootHash] ? "YES" : "NO");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		processTestCase();
		cout << '\n';
	}

	return 0;
}
