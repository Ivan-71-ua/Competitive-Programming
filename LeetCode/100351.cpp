#include <bits/stdc++.h>


class Solution {
public:
	int numberOfAlternatingGroups(std::vector<int>& colors, int k) {
		int n = colors.size();
		std::vector<int> extendedColors = colors;
		extendedColors.insert(extendedColors.end(), colors.begin(), colors.begin() + k);
		std::vector<int> dp(extendedColors.size(), 1);
		for (int i = 1; i < extendedColors.size(); ++i) {
			if (extendedColors[i] != extendedColors[i - 1]) {
					dp[i] = dp[i - 1] + 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (dp[i + k - 1] >= k) {
					ans++;
			}
		}
		return ans;
	}
};



int main(){
	Solution ans;
	std::vector<int> ss{0, 1, 0, 0, 1, 0, 1};
	ans.numberOfAlternatingGroups(ss, 6);
}