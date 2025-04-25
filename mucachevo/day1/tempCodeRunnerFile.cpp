#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> tree[MAXN];
long long totalPaths = 0;

void dfs(int node, int parent, int depth, int k) {
	if (depth == k) {
		totalPaths++;
		return;
	}

	for (int neighbor : tree[node]) {
		if (neighbor != parent) {
			dfs(neighbor, node, depth + 1, k);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		dfs(i, -1, 0, k);
	}

	// Кожен шлях враховується двічі (для кожної вершини), тому ділимо на 2
	cout << totalPaths / 2 << endl;

	return 0;
}
