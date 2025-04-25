#include <bits/stdc++.h>





class Solution {
    const int MOD = 1e9 + 7;
    long long INF = LONG_LONG_MAX;
    std::vector<std::pair<int, int>> tree;
    std::vector<std::pair<int, int>> tmp;

    std::pair<int, int> combine(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first < b.first) 
        return a;
    if (a.first > b.first)
        return b;
    return {a.first, std::min(a.second, b.second)};
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = {tmp[tl].first, tmp[tl].second};
    } else {
        int tm = (tl + tr) / 2;
        build( v* 2, tl, tm);
        build( v* 2+1, tm+1, tr);
        tree[v] = combine(tree[v*2], tree[v*2+1]);
    }
}

std::pair<int, int> get_min(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {INF, 0};
    if (l == tl && r == tr)
        return tree[v];
    int tm = (tl + tr) / 2;
    return combine(get_min(v*2, tl, tm, l, std::min(r, tm)), 
                   get_min(v*2+1, tm+1, tr, std::max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, std::pair<int, int> new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v] = combine(tree[v*2], tree[v*2+1]);
    }
}
public:
    std::vector<int> getFinalState(std::vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            tmp.push_back({nums[i], i});
        }
        tree.resize(4 * n);
        build(1, 0, n - 1);
        for (int i = 0; i < k; i++)
        {
            std::pair<int, int> min = get_min(1, 0, n - 1, 0, n - 1);
            tmp[min.second].first = (multiplier * tmp[min.second].first) % MOD;
            update(1, 0, n - 1, min.second, tmp[min.second]);
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = tmp[i].first;
        }
        return nums;
    }
};