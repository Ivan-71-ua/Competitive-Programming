#include <bits/stdc++.h>

std::vector<int> arr(100000 + 4);
std::vector<int> tree(400000 + 4);

void built_tree(int ver, int lt, int rt) {
	if (rt == lt) {
		tree[ver] = arr[lt];
		return;
	}
	int mid = (rt + lt) / 2;
	built_tree(ver * 2, lt, mid);
	built_tree(ver * 2 + 1, mid + 1, rt);
	tree[ver] = std::max(tree[ver * 2], tree[ver * 2 + 1]);
}

int get_max(int l, int r, int ver, int lt, int rt) {
	if (l <= lt && rt <= r) { 
		return tree[ver];
	}
	if (r < lt || rt < l) { 
		return INT32_MIN;
	}
	int mid = (rt + lt) / 2;
	return std::max(get_max(l, r, ver * 2, lt, mid), get_max(l, r, ver * 2 + 1, mid + 1, rt));
}

void update(int idx, int val, int ver, int lt, int rt) {
	if (idx <= lt && rt <= idx) { 
		arr[idx] = val;
		tree[ver] = val;
		return;
	}
	if (idx < lt || rt < idx) {
		return;
	}
	int mid = (rt + lt) / 2;
	update(idx, val, ver * 2, lt, mid);
	update(idx, val, ver * 2 + 1, mid + 1, rt);
	tree[ver] = std::max(tree[ver * 2], tree[ver * 2 + 1]);
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
			std::cout << get_max(a, b, 1, 0, n - 1) << '\n';
		}
		if (k == 2) {
			int id, val;
			std::cin >> id >> val;
			update(id, arr[id] + val, 1, 0, n - 1);
		}
	}
	return 0;
}
