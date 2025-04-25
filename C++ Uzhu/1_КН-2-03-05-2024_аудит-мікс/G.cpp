#include <bits/stdc++.h>

const int MOD = 9929;
std::vector<std::vector<int>> dp(507, std::vector<int>(507));

int Biinomic(int n, int k) {
	if(dp[n][k] > 0)
		return dp[n][k];
	if(n - k < k)
		return Biinomic(n, n - k);
	if(!k)
		return dp[n][k] = 1;
	return dp[n][k] = (Biinomic(n - 1, k) + Biinomic(n - 1, k - 1)) % MOD;
}

int main() {
	int n, k;
	std::cin >> n >> k;
	std::cout << Biinomic(n, k);
}