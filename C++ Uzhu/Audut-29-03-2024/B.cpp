#include <bits/stdc++.h>



int min_price(int a, int b, std::vector<std::vector<int>> &dp, std::vector<int> &cuts) {
	if (b - a == 1) return 0; 
	if (dp[a][b] != INT_MAX) return dp[a][b]; 
	for (int i = a + 1; i < b; i++) {
		
		int temp = cuts[b] - cuts[a] + min_price(a, i, dp, cuts) + min_price(i, b, dp, cuts);
		dp[a][b] = std::min(dp[a][b], temp);
	}
	return dp[a][b];
}

int main() {
	int l;
	while (std::cin >> l && l != 0) {
		int n;
		std::cin >> n;
		std::vector<int> cuts(n + 2); 
		cuts[0] = 0; 
		cuts[n + 1] = l; 
		for (int i = 1; i <= n; i++) {
				std::cin >> cuts[i];
		}
		std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, INT_MAX)); 
		std::cout << "The minimum cutting is " << min_price(0, n + 1, dp, cuts) << ".\n";
	}
}
