#include <bits/stdc++.h>


class Solution {
public:
long long maximumTotalDamage(std::vector<int>& power) {
	std::unordered_map<int, int> damageCount;
	for (int p : power) {
		damageCount[p]++;
	}
	std::vector<int> uniqueDamages;
	for (const auto& entry : damageCount) {
		uniqueDamages.push_back(entry.first);
	}
	std::sort(uniqueDamages.begin(), uniqueDamages.end());
	int n = uniqueDamages.size();
	std::vector<long long> dp(n, 0);
	for (int i = 0; i < n; ++i) {
		long long currentDamage = uniqueDamages[i];
		long long currentTotalDamage = currentDamage * damageCount[currentDamage];
		
		if (i == 0) {
			dp[i] = currentTotalDamage;
		} else {
			int prevIndex = i - 1;
			while (prevIndex >= 0 && uniqueDamages[prevIndex] >= currentDamage - 2) {
					--prevIndex;
			}
			
			if (prevIndex >= 0) {
					dp[i] = std::max(dp[i-1], currentTotalDamage + dp[prevIndex]);
			} else {
					dp[i] = std::max(dp[i-1], currentTotalDamage);
			}
		}
	}
	return dp[n-1];
   }
};