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

    int n;
    cin >> n;
    set <int> have;
    string s;
    int ans = 0;
    const int N = 1e9;
    for (int i = 0, x; i < n; i++) {
        cin >> s >> x;
        if (s[0] == '+') {
            x += ans;
            if (x >= N) x -= N;
            if (x < 0) x += N;
            have.insert(x);
            ans = 0;
        }
        else {
            auto it = have.lower_bound(x);
            if (it == have.end()) {
                cout << "-1\n";
                ans = -1;
            }
            else {
                cout << *it << '\n';
                ans = *it;
            }
        }
    }
}