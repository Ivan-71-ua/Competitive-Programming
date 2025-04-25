#include <bits/stdc++.h>

using namespace std;

vector<int> fk_tree;

void update(int idx, int d, int n) {
	while (idx < n) {
		fk_tree[idx] += d;
		idx = idx | (idx + 1);
	}
}

int query(int idx) {
	int sum = 0;
	while (idx >= 0) {
		sum += fk_tree[idx];
		idx = (idx & (idx + 1)) - 1;
	}
	return sum;
}

int main() {
	int n, A, Q;
	cin >> n >> A >> Q;
	
	fk_tree.resize(n, 0);
	
	for (int i = 0; i < A + Q; i++) {
		char type;
		cin >> type;
		if (type == 'A') {
			int l, r, d;
			cin >> l >> r >> d;
			update(l, d, n);
			update(r + 1, -d, n);
		} else if (type == 'Q') {
			int idx;
			cin >> idx;
			cout << query(idx) << '\n';
		}
	}
}
