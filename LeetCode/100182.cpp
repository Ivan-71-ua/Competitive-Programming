#include <bits/stdc++.h>


class Solution {
public:
	long long maximumPoints(std::vector<int>& enemyEnergies, int currentEnergy) {
		std::stable_sort(enemyEnergies.begin(), enemyEnergies.end());
		long long take = 0;
		long long give = enemyEnergies.size() - 1;
		long long ans = 0;
		while(take <= give) {
			if(currentEnergy >= enemyEnergies[take]) {
				ans += currentEnergy / enemyEnergies[take];
				currentEnergy = currentEnergy % enemyEnergies[take];
			} else {
				if(ans > 0) {
					currentEnergy += enemyEnergies[give--];
				} else {
					break;
				}
			}
		}
		return ans;
	}
};

int main() {
	std::vector<int> ss{3, 2, 2};
	Solution ans;
	ans.maximumPoints(ss, 2);
}