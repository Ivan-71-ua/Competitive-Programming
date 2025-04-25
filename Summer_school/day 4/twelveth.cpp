#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

struct Interval {
	int l, r;
};

bool compare(const Interval &a, const Interval &b) {
	if (a.r == b.r)
		return a.l > b.l;
	return a.r < b.r;
}

void update(std::vector<int> &fenwick_tree, int idx, int value) {
	while (idx < fenwick_tree.size()) {
		fenwick_tree[idx] = std::max(fenwick_tree[idx], value);
		idx += idx & -idx;
	}
}

int query(const std::vector<int> &fenwick_tree, int idx) {
	int max_value = 0;
	while (idx > 0) {
		max_value = std::max(max_value, fenwick_tree[idx]);
		idx -= idx & -idx;
	}
	return max_value;
}

int main() {
	fast
	int n;
	std::cin >> n;
	std::vector<Interval> intervals(n);
	for (int i = 0; i < n; i++) {
		std::cin >> intervals[i].l >> intervals[i].r;
	}
	std::stable_sort(intervals.begin(), intervals.end(), compare);
	std::map<int, int> compress;
	for (int i = 0; i < n; i++) {
		compress[intervals[i].l] = 0;
	}
	int idx = 0;
	for (std::map<int, int>::iterator it = compress.begin(); it != compress.end(); it++) {
		it->second = ++idx;
	}
	std::vector<int> fenwick_tree(idx + 1, 0);
	int max_subset_size = 0;
	for (int i = 0; i < n; i++) {
		int l_compressed = compress[intervals[i].l];
		int current_max = query(fenwick_tree, l_compressed - 1) + 1;
		update(fenwick_tree, l_compressed, current_max);
		max_subset_size = std::max(max_subset_size, current_max);
	}
	std::cout << max_subset_size << '\n';
	return 0;
}
