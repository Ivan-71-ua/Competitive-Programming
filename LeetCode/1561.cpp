#include <bits/stdc++.h>

class Solution {
public:
	int maxCoins(std::vector<int>& piles) {
		int times = piles.size() / 3;
		int i = -1;
		std::stable_sort(piles.begin(), piles.end(), std::greater());
		int res = 0;
		while(times--) {
			i += 2;
			res += piles[i];
		}
		return res;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{9, 8, 7, 6, 5, 1, 2, 3, 4};
	ans.maxCoins(ss);
}