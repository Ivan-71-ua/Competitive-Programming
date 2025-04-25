#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#define int long long
#define pb push_back
#define x first
#define y second
#define mk(a,b) make_pair(a,b)
#define rr return 0
#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#undef M_PI
#define M_PI 3.14159265358979323846264338327950288419

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class value, class cmp = less<value> >
using ordered_set = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class value, class cmp = less_equal<value> >
using ordered_multiset = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = less<key> >
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/// find_by_order()
/// order_of_key()
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int randll(int l = INT_MIN, int r = INT_MAX) {
    return uniform_int_distribution<int>(l, r)(rng);
}

inline ld randld(ld l = INT_MIN, ld r = INT_MAX) {
    return uniform_real_distribution<ld>(l, r)(rng);
}

const int INF = 2e9 + 1, MOD = 998244353; /// think
const ll LINF = 2e18 + 11;

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
inline bool inside (int x, int y, int n, int m) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

template<class T> bool umin (T &a, T b) {return a > b ? (a = b, true) : false; }
template<class T> bool umax (T &a, T b) {return a < b ? (a = b, true) : false; }


main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    multiset <int> have;
    deque <int> last;
    bool ok = true;
    for (int i = 0, t, x; i < q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            last.pb(x);
        }
        else if (t == 2) {
            if (have.empty()) {
                cout << last.front() << '\n';
                last.pop_front();
            }
            else {
                cout << *have.begin() << '\n';
                have.erase(have.begin());
            }
        }
        else {
            multiset <int> cur;
            while (!last.empty()) {
                cur.insert(last.back());
                last.pop_back();
            }
            if (sz(have) < sz(cur)) {
                swap(have, cur);
            }
            for (int j : cur) {
                have.insert(j);
            }
        }
    }
}
