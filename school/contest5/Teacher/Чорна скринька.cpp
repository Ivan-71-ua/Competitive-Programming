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




int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set <pii> have = {{-2 * inf, -1}};
    int n, m;
    cin >> n >> m;
    auto it = have.begin();
    vector <int> a(n);
    for (auto &i : a) cin >> i;
    for (int i = 0, b, j = 0; i < m; i++) {
        cin >> b;
        while (j < b) {
            have.insert({a[j], j});
            if (a[j] < it->first) {
                --it;
            }
            ++j;
        }
        ++it;
        cout << it->first << '\n';
    }
}