//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4")

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define fi first
#define se second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

template<typename T>
bool umin(T &a, T b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T>
bool umax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifdef KIVI
#define DEBUG for (bool _FLAG = true; _FLAG; _FLAG = false)
#define LOG(...) print(#__VA_ARGS__" ::", __VA_ARGS__) << endl
template <class ...Ts> auto &print(Ts ...ts) { return ((cerr << ts << " "), ...); }
#else
#define DEBUG while (false)
#define LOG(...)
#endif

const int max_n = -1, inf = 1000111222;


const ll linf = inf * 1ll * inf;



int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> a(n * 3);
    for (auto &i : a) cin >> i;
    vector <ll> pref(3 * n, -linf);
    ll s = 0;
    priority_queue<int, vector <int>, greater<int> > q;
    for (int i = n - 1, j = 0; i < 3 * n; i++) {
        while (j <= i) {
            s += a[j];
            q.push(a[j]);
            ++j;
        }
        while (len(q) > n) {
            s -= q.top();
            q.pop();
        }
        pref[i] = s;
    }
    priority_queue <int> qq;
    s = 0;
    ll ans = -linf;
    for (int i = 2 * n, j = 3 * n - 1; i > 0; i--) {
        while (j >= i) {
            s += a[j];
            qq.push(a[j]);
            --j;
        }
        while (len(qq) > n) {
            s -= qq.top();
            qq.pop();
        }
        umax(ans, pref[i - 1] - s);
    }
    cout << ans << '\n';
}