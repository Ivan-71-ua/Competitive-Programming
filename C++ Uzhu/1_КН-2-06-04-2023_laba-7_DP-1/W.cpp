#include <bits/stdc++.h>
#define int long long

const int MOD = 1000000007;

int32_t main() {
	int n; 
	std::cin >> n;
	std::vector<int >dp(n + 3, 0);
	dp[0] = 1; dp[1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % MOD;
	}
	std::cout << (dp[n-1] * 2) % MOD;
}