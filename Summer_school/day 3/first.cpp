#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
//#define int long long


const int MAXN = 1000000;
int n, m;
int a[MAXN];
int tree[4 * MAXN]; 


void build_tree(int v, int tl, int tr) {
	if (tl == tr) {
		tree[v] = a[tl];
	} else {
		int tm = (tl + tr) / 2;
		build_tree(v * 2, tl, tm);
		build_tree(v * 2 + 1, tm + 1, tr);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}


int get_sum(int v, int tl, int tr, int l, int r) {
	if (l > r) 
		return 0; 
	if (l == tl && r == tr) 
		return tree[v]; 
	int tm = (tl + tr) / 2;
	return get_sum(v * 2, tl, tm, l, std::min(r, tm))
		+ get_sum(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
}


void update(int v, int tl, int tr, int idx, int new_val) {
	if (tl == tr) {
		a[idx] = new_val;
		tree[v] = new_val; 
	} else {
		int tm = (tl + tr) / 2;
		if (idx <= tm)
			update(v * 2, tl, tm, idx, new_val);  
		else
			update(v * 2 + 1, tm + 1, tr, idx, new_val);  
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}

int32_t main() {
	fast
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	build_tree(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int type;
		std::cin >> type;
		if (type == 1) {
			int l, r;
			std::cin >> l >> r;
			l--, r--; 
			std::cout << get_sum(1, 0, n - 1, l, r) << "\n";
		} else if (type == 2) {
			int idx, d;
			std::cin >> idx >> d;
			idx--; 
			update(1, 0, n - 1, idx, a[idx] + d);
		}
	}
}
