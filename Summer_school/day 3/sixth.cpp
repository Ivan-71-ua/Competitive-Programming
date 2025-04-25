#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

typedef std::vector<std::vector<int>> graph;

std::vector<int> a;
std::vector<int> subtree_values;
std::vector<int> first_occurrence;
std::vector<int> seg_tree;
std::vector<int> lazy;
std::vector<int> subtree_end;
std::vector<char> visited;

void dfs(const graph &g, int v) {
    visited[v] = true;
    first_occurrence[v] = subtree_values.size();
    subtree_values.push_back(a[v]);
    for (const auto &u : g[v]) {
        if (!visited[u]) {
            dfs(g, u);
            subtree_values.push_back(a[v]);
        }
    }
    subtree_end[v] = subtree_values.size() - 1;
}

void build_tree(int v, int tl, int tr) {
    if (tl == tr) {
        seg_tree[v] = subtree_values[tl];
    } else {
        int tm = (tl + tr) / 2;
        build_tree(v * 2, tl, tm);
        build_tree(v * 2 + 1, tm + 1, tr);
        seg_tree[v] = std::max(seg_tree[v * 2], seg_tree[v * 2 + 1]);
    }
}

void push(int v) {
    if (lazy[v] != 0) {
        seg_tree[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];
        seg_tree[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        seg_tree[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, std::min(r, tm), addend);
        update(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, addend);
        seg_tree[v] = std::max(seg_tree[v * 2], seg_tree[v * 2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return LLONG_MIN;
    if (l <= tl && tr <= r)
        return seg_tree[v];
    push(v);
    int tm = (tl + tr) / 2;
    return std::max(query(v * 2, tl, tm, l, std::min(r, tm)), query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
}

int32_t main() {
    fast
    int n, q;
    std::cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    graph g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    subtree_values.reserve(2 * n);
    first_occurrence.resize(n + 1);
    subtree_end.resize(n + 1);
    visited.assign(n + 1, false);

    dfs(g, 1);

    int m = subtree_values.size();
    seg_tree.resize(4 * m);
    lazy.assign(4 * m, 0);

    build_tree(1, 0, m - 1);

    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int type, v, x;
        std::cin >> type >> v;
        if (type == 1) {
            std::cin >> x;
            int l = first_occurrence[v];
            int r = subtree_end[v];
            update(1, 0, m - 1, l, r, x);
        } else {
            int l = first_occurrence[v];
            int r = subtree_end[v];
            std::cout << query(1, 0, m - 1, l, r) << '\n';
        }
    }

    return 0;
}
