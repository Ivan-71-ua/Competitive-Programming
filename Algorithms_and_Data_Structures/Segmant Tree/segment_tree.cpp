#include <bits/stdc++.h>

std::vector<int> arr(100000 + 4);
std::vector<int> tree(400000 + 4);

void built_tree(int ver, int lt, int rt) {
	if (lt == rt) {
		tree[ver] = arr[lt];
		return;
	}
	int mid = (lt + rt) / 2;
	built_tree(ver * 2, lt, mid);
	built_tree(ver * 2 + 1, mid + 1, rt);
	tree[ver] = tree[ver * 2] + tree[ver * 2 + 1];
}

int get_sum(int l, int r, int v, int lt, int rt) {
	if (l <= lt && rt <= r) {
		return tree[v];
	}
	if (rt < l || r < lt) {
		return 0;
	}
	int mid = (rt + lt) / 2;
	return get_sum(l, r, v * 2, lt, mid) + get_sum(l, r, v * 2 + 1, mid + 1, rt);
}

void update(int idx, int val, int ver, int lt, int rt) {
	if (lt == rt) {
		arr[idx] = val;
		tree[ver] = val;
		return;
	}
	if (rt < idx || idx < lt) {
		return;
	}
	int mid = (rt + lt) / 2;
	update(idx, val, ver * 2, lt, mid);
	update(idx, val, ver * 2 + 1, mid + 1, rt);
	tree[ver] = tree[ver * 2] + tree[ver * 2 + 1];
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	built_tree(1, 0, n - 1);
	while (true) {
		int k;
		std::cout << "-_-\n";
		std::cin >> k;
		if (k == 0) break;
		if (k == 1) {
			int a, b;
			std::cin >> a >> b;
			std::cout << get_sum(a, b, 1, 0, n - 1) << '\n';
		}
		if (k == 2) {
			int id, val;
			std::cin >> id >> val;
			update(id, val + arr[id], 1, 0, n - 1);
		}
	}
	return 0;
}
