// LUOGU_RID: 126420474
/*
 * @Author:             cmk666
 * @Created time:       2023-09-28 09:34:09
 * @Last Modified time: 2023-09-28 10:29:58
 */
#pragma GCC optimize("Ofast", "unroll-loops")
#include<map>
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 200005;
const int INF = INT_MAX;

struct SegmentTreeY {
    int tree[4 * MAXN];

    SegmentTreeY() {
        for (int i = 0; i < 4 * MAXN; ++i) {
            tree[i] = INF;
        }
    }

    void update(int node, int start, int end, int pos, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (pos <= mid)
                update(2 * node, start, mid, pos, val);
            else
                update(2 * node + 1, mid + 1, end, pos, val);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int y1) {
        if (start > y1) return tree[node];
        if (end <= y1) return INF;
        int mid = (start + end) / 2;
        return min(query(2 * node, start, mid, y1), query(2 * node + 1, mid + 1, end, y1));
    }
};

struct SegmentTreeX {
    SegmentTreeY tree[4 * MAXN];
    int n;

    SegmentTreeX(int size) : n(size) {}

    void update(int node, int start, int end, int x, int y, int val) {
        if (start == end) {
            tree[node].update(1, 0, n - 1, y, val);
        } else {
            int mid = (start + end) / 2;
            if (x <= mid)
                update(2 * node, start, mid, x, y, val);
            else
                update(2 * node + 1, mid + 1, end, x, y, val);
            tree[node].update(1, 0, n - 1, y, val);
        }
    }

    int query(int node, int start, int end, int x1, int y1) {
        if (start > x1) {
            return tree[node].query(1, 0, n - 1, y1);
        }
        if (end <= x1) {
            return INF;
        }
        int mid = (start + end) / 2;
        return min(query(2 * node, start, mid, x1, y1), query(2 * node + 1, mid + 1, end, x1, y1));
    }

    void add(int x, int y) {
        update(1, 0, n - 1, x, y, y);
    }

    void remove(int x, int y) {
        update(1, 0, n - 1, x, y, INF);
    }

    pair<int, int> find(int x, int y) {
        int result = query(1, 0, n - 1, x, y);
        if (result == INF) {
            return {-1, -1};
        }
        return {x + 1, result};
    }
};

int main() {
    int n;
    cin >> n;

    SegmentTreeX segmentTree(MAXN);

    for (int i = 0; i < n; ++i) {
        string command;
        int x, y;
        cin >> command >> x >> y;

        if (command == "add") {
            segmentTree.add(x, y);
        } else if (command == "remove") {
            segmentTree.remove(x, y);
        } else if (command == "find") {
            pair<int, int> result = segmentTree.find(x, y);
            if (result.first == -1) {
                cout << -1 << endl;
            } else {
                cout << result.first << " " << result.second << endl;
            }
        }
    }

    return 0;
}
