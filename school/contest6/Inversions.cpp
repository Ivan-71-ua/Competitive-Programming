#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

void build(std::vector<std::set<int>>& tree, int node, int start, int end, const std::vector<int>& initialSet) {
    if (start == end) {
        tree[node].insert(initialSet[start]);
        return;
    }

    int mid = (start + end) / 2;
    build(tree, 2 * node + 1, start, mid, initialSet);
    build(tree, 2 * node + 2, mid + 1, end, initialSet);
    tree[node].insert(tree[2 * node + 1].begin(), tree[2 * node + 1].end());
    tree[node].insert(tree[2 * node + 2].begin(), tree[2 * node + 2].end());
}

void update(std::vector<std::set<int>>& tree, int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node].clear();
        tree[node].insert(val);
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(tree, 2 * node + 1, start, mid, idx, val);
    } else {
        update(tree, 2 * node + 2, mid + 1, end, idx, val);
    }

    tree[node].clear();
    tree[node].insert(tree[2 * node + 1].begin(), tree[2 * node + 1].end());
    tree[node].insert(tree[2 * node + 2].begin(), tree[2 * node + 2].end());
}

int query(const std::vector<std::set<int>>& tree, int node, int start, int end, int left, int right, int k) {
    if (left > end || right < start) {
        return -1;
    }

    if (left <= start && right >= end) {
        auto it = tree[node].begin();
        std::advance(it, k - 1);
        return *it;
    }

    int mid = (start + end) / 2;
    int leftResult = query(tree, 2 * node + 1, start, mid, left, right, k);
    if (leftResult != -1) {
        return leftResult;
    }

    return query(tree, 2 * node + 2, mid + 1, end, left, right, k);
}

int main() {
	fast;

	int n;
	std::cin >> n;

	std::vector<int> initialSet(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> initialSet[i];
    }

    std::vector<std::set<int>> tree(4 * n);
    build(tree, 0, 0, n - 1, initialSet);

    int t;
    std::cin >> t;

    while (t--) {
        char op;
        std::cin >> op;

        if (op == '?') {
            int k;
            std::cin >> k;
            std::cout << query(tree, 0, 0, n - 1, 0, n - 1, k) << '\n';
        } else if (op == '=') {
            int idx, val;
            std::cin >> idx >> val;
            update(tree, 0, 0, n - 1, idx - 1, val);
        }
    }

}
