
#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

std::vector<std::set<int>> tree;
std::vector<std::set<int>> lazy;

std::set<int> merge(const std::set<int>& left, const std::set<int>& right) {
    std::set<int> result = left;
    result.insert(right.begin(), right.end());
    return result;
}

void build(int node, int start, int end, const std::vector<int>& cameras) {
    if (start == end) {
        tree[node].insert(cameras[start]);
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node + 1, start, mid, cameras);
    build(2 * node + 2, mid + 1, end, cameras);
    tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
}

std::set<int> query(int node, int start, int end, int left, int right) {
    if (!lazy[node].empty()) {
        tree[node] = lazy[node];

        if (start != end) {
            lazy[2 * node + 1] = lazy[node];
            lazy[2 * node + 2] = lazy[node];
        }

        lazy[node].clear();
    }

    if (right < start || left > end)
        return std::set<int>();

    if (left <= start && right >= end)
        return tree[node];

    int mid = (start + end) / 2;
    std::set<int> leftResult = query(2 * node + 1, start, mid, left, right);
    std::set<int> rightResult = query(2 * node + 2, mid + 1, end, left, right);
    return merge(leftResult, rightResult);
}

void update(int node, int start, int end, int left, int right, int val) {
    if (!lazy[node].empty()) {
        tree[node] = lazy[node];

        if (start != end) {
            lazy[2 * node + 1] = lazy[node];
            lazy[2 * node + 2] = lazy[node];
        }

        lazy[node].clear();
    }

    if (right < start || left > end)
        return;

    if (left <= start && right >= end) {
        tree[node].clear();
        tree[node].insert(val);

        if (start != end) {
            lazy[2 * node + 1].insert(val);
            lazy[2 * node + 2].insert(val);
        }

        return;
    }

    int mid = (start + end) / 2;
    update(2 * node + 1, start, mid, left, right, val);
    update(2 * node + 2, mid + 1, end, left, right, val);
    tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
}

int main() {
	fast;
	int n;
   std::cin >> n;

   std::vector<int> cameras(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> cameras[i];
    }

    int t;
   std::cin >> t;

    tree.resize(4 * n);
    lazy.resize(4 * n);

    build(0, 0, n - 1, cameras);

    for (int i = 0; i < t; ++i) {
        char op;
        std::cin >> op;

        if (op == '?') {
            int l, r;
            std::cin >> l >> r;
            std::set<int> result = query(0, 0, n - 1, l - 1, r - 1);
            std::cout << result.size() << std::endl;
        } else if (op == '=') {
            int idx, val;
            std::cin >> idx >> val;
            update(0, 0, n - 1, idx - 1, idx - 1, val);
        }
    }
}
