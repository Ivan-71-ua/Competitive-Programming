#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("arch=icelake-server")
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <cctype>
#include <map>
#include <string>
#include <stack>
#include <cmath>
#include <queue>
 
using namespace std;
using ll = long long;
 
template<typename T>
using vec = vector<T>;
 
const int max_n = 3e3 + 124, INF = 1000111222, MOD = 1e9 + 7;
 
const ll inf = INF * 1ll * INF;
 
void solve(){
    ll n, m, k;
    cin>>n>>k>>m;
    k = min(k, m / 2);
    ll dp[m + 1][k + 1];
    dp[0][0] = 1;
    for(int i = 1; i <= k; i++)
        dp[0][i] = 0;
    ll ans = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            dp[i][j] = ((j > 0 ? dp[i - 1][j - 1] : 0) + (j < k ? dp[i - 1][j + 1] : 0)) % MOD;
        }
        ans = (ans + dp[i][0]) % MOD;
    }
    cout<<(2ll * n * ans)%MOD<<'\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int numTest = 1;
//    cin>>numTest;
    while(numTest--)
        solve();
}