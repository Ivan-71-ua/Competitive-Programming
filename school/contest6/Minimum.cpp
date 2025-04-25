#include <bits/stdc++.h>



int n;
int value[100000];
int tree[500004];

void build_tree(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = value[tl];
    } else {
        int tm = (tl + tr) / 2;
        build_tree(v * 2, tl, tm);
        build_tree(v * 2 + 1, tm + 1, tr);
        tree[v] = std::min(tree[v * 2], tree[v * 2 + 1]);
    }
}

int get_min(int l, int r, int v, int tl, int tr) {
    if (l <= tl && tr <= r) {
        return tree[v];
    }

    if (tr < l || r < tl) {
        return INT_MAX;
    }

    int tm = (tl + tr) / 2;
    return std::min(get_min(l, r, v * 2,     tl,     tm),
               get_min(l, r, v * 2 + 1, tm + 1, tr));
}

void update(int idx, int val, int v, int tl, int tr) {
    if (idx <= tl && tr <= idx) {
        value[idx] = val;
        tree[v] = val;
        return;
    }

    if (tr < idx || idx < tl) {
        return;
    }

    int tm = (tl + tr) / 2;
    update(idx, val, v * 2,     tl,     tm);
    update(idx, val, v * 2 + 1, tm + 1, tr);
    tree[v] = std::min(tree[v * 2], tree[v * 2 + 1]);
}

int main() {
   int n;
   std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> value[i];
    }
    build_tree(1, 0, n - 1);
    int q;
    std::cin >> q;
    while (q--) {
        char ask;
        int k,p;
        std::cin >> ask;
        std::cin >> k >> p;
        if(ask == '?') {
            std::cout << get_min(k -1, p-1, 1, 0, n - 1) << '\n';
        } else {
            update(k-1, p, 1, 0, n - 1);
        }
    }
}