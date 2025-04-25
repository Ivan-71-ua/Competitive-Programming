#include <bits/stdc++.h>
#define int long long

int32_t main() {
    int n;
    std::cin >> n;
    std::vector<long long> dp(n + 5, 0);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int k = 1LL << n;
    int d = dp[n];
    int gc = std::gcd(k, d);
    std::cout << k / gc << '/' << d / gc;
}