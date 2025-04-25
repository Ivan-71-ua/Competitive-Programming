#include <bits/stdc++.h>
#define ll long long


bool canWin(int n, int k, const std::string& stones) {
   std::vector<bool> dp(n + 1, false);

   for (int i = 1; i <= n; ++i) {
      if (stones[i - 1] == 'C') {
         dp[i] = dp[i - 1];
      }
      else if (i >= k && dp[i - k]) {
         dp[i] = true;
      }
   }
	return dp[n];
}

int main() {
   int n, k;
   std::cin >> n >> k;
   std::string stones;
   std::cin >> stones;
   std::string result = canWin(n, k, stones) ? "DA" : "NE";
   std::cout << result << std::endl;

}
