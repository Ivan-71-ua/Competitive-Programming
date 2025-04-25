#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
#define int long long
const int INF = LONG_MAX;
const int MAX_L = 200000 + 7;
std::vector<int> arr(MAX_L);
std::vector<int> tree(MAX_L * 4);
std::vector<int> lazy(MAX_L * 4);

void build(int v, int lt, int rt) {
	if (lt == rt) {
		tree[v] = arr[lt];
	} else {
		int mid = (lt + rt) / 2;
		build(v * 2, lt, mid);
		build(v * 2 + 1, mid + 1, rt);
		tree[v] = std::min(tree[v * 2], tree[v * 2 + 1]);  
	}
}

void push(int v) {
	tree[v * 2] += lazy[v];
	lazy[v * 2] += lazy[v];
	tree[v * 2 + 1] += lazy[v];
	lazy[v * 2 + 1] += lazy[v];
	lazy[v] = 0;
}

void update(int v, int lt, int rt, int l, int r, int add) {
	if (l > r) return;
	if (lt == l && rt == r) {
		tree[v] += add;
		lazy[v] += add;
	} else {
		push(v);
		int mid = (lt + rt) / 2;
		update(v * 2, lt, mid, l, std::min(r, mid), add);
		update(v * 2 + 1, mid + 1, rt, std::max(mid + 1, l), r, add);
		tree[v] = std::min(tree[v * 2], tree[v * 2 + 1]); 
	}
}

int query(int v, int lt, int rt, int l, int r) {
	if (l > r) return INF; 
	if (lt == l && rt == r) {
		return tree[v];
	}
	push(v);
	int mid = (lt + rt) / 2;
	return std::min(query(v * 2, lt, mid, l, std::min(r, mid)), query(v * 2 + 1, mid + 1, rt, std::max(mid + 1, l), r));
}

int32_t main() {
	int n, m;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	build(1, 0, n - 1);
	std::cin >> m;
	std::string s;
	std::getline(std::cin, s);  
	while (m--) {
		std::getline(std::cin, s);
		std::stringstream parse(s);
		int lf, rg, v = -1;
		parse >> lf >> rg;
		if (parse >> v) { 
			if (lf > rg) {
				update(1, 0, n - 1, lf, n - 1, v);
				update(1, 0, n - 1, 0, rg, v);
			} else {
				update(1, 0, n - 1, lf, rg, v);
			}
		} else {  
			if (lf > rg) {
				std::cout << std::min(query(1, 0, n - 1, lf, n - 1), query(1, 0, n - 1, 0, rg)) << '\n';
			} else {
				std::cout << query(1, 0, n - 1, lf, rg) << '\n';
			}
		}
	}
}
