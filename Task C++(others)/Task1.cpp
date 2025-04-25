// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

// #define _GLIBCXX_DEBUG
// #define _GLIBCXX_DEBUG_PEDANTIC

#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>

// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;


const int MOD = 998244353;
const long double PI = 3.141592653589793;
using ll = long long;
const ll INF = 1e18;

#define int ll

// template<typename T>
// using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

// template<typename K, typename V>
// using hash_table = cc_hash_table<K, V, hash<K>>;

template<typename T>
using graph = vector<vector<T>>;

template<typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (auto& i: a) {
        in >> i;
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
    for (auto& i: a) {
        out << i << " ";
    }
    return out;
}

ll fast_pow(ll a, ll b, ll mod) {
    if (b == 0)
        return 1;
    if (b % 2) {
        return (1ll * a * fast_pow(a, b - 1, mod)) % mod;
    }
    ll k = fast_pow(a, b / 2, mod);
    return (1ll * k * k) % mod;
}

ll fast_pow(ll a, ll b) {
    if (b == 0)
        return 1;
    if (b % 2) {
        return (1ll * a * fast_pow(a, b - 1));
    }
    ll k = fast_pow(a, b / 2);
    return (1ll * k * k);
}
const int N = 10400;

bool check(string& s) {
 for (int k = 1; 3 * k <= s.size(); k++) {
  string s1 = string(s.end() - k, s.end());
  string s2 = string(s.end() - 2 * k, s.end() - k);
  string s3 = string(s.end() - 3 * k, s.end() - 2 * k);
  if (s1 == s2 && s2 == s3)
   return false;
 }
 return true;
}

void solve() {
 int n;
 cin >> n;
 vector<string> strs = {"a", "b"};
 for (int i = 2; i <= n; i++) {
  vector<string> nw;
  for (auto st : strs) {
   string x = st;
   x += 'a';
   if (check(x))
    nw.push_back(x);
   x.pop_back();
   if (x.back() == 'a') {
    x += 'b';
    if (check(x)) {
     nw.push_back(x);
    }
   }
  }
  strs = nw;
 }
 cout << strs.size();
}

int32_t main(int32_t argc, const char * argv[]) {
 cin.tie(0);
 cout.tie(0);
 ios_base::sync_with_stdio(0);
    // insert code here...
    int tt= 1;
    // std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}