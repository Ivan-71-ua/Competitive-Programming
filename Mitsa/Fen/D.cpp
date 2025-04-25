#include <bits/stdc++.h>
using namespace std;

void update(vector<int>& fenwick_tree, int idx, int delta) {
	while (idx < fenwick_tree.size()) {
		fenwick_tree[idx] += delta;
		idx = idx | (idx + 1);
	}
}

int query(const vector<int>& fenwick_tree, int idx) {
	int sum = 0;
	while (idx >= 0) {
		sum += fenwick_tree[idx];
		idx = (idx & (idx + 1)) - 1;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<int> cubes(2 * n);
	
	for (int i = 0; i < 2 * n; ++i) {
		cin >> cubes[i];
	}

	unordered_map<int, vector<int>> positions;
	for (int i = 0; i < 2 * n; ++i) {
		positions[cubes[i]].push_back(i);
	}

	vector<int> fenwick_tree(2 * n, 0);

	int swaps = 0;

	for (int num = 1; num <= n; ++num) {
		int first_pos = positions[num][0];
		int second_pos = positions[num][1];

		int left_swaps = query(fenwick_tree, first_pos);
		int right_swaps = query(fenwick_tree, second_pos);

		if (right_swaps - left_swaps > 1) {
			swaps += right_swaps - left_swaps - 1;
		}

		update(fenwick_tree, first_pos, 1);
		update(fenwick_tree, second_pos, 1);
	}

	cout << swaps << endl;

	return 0;
}
