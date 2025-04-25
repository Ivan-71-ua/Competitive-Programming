#include <bits/stdc++.h>
#define int long long
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int32_t main() {
    fast;
    int n, k;
    std::cin >> n >> k;
    int a = k / n;
    int b = k  % n;
    int res = 0;
    if(a - 1 > -1)
        res += k - n;
    if(a + 1 < n)
        res += k + n;
    if(b - 1 > -1)
        res += k - 1;
    if(b + 1 < n)
        res += k + 1;
    std::cout << res;
}