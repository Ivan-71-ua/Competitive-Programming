#include <bits/stdc++.h>

class Solution {
	long long can(std::vector<int>& candies, long long cnt_candies) {
		long long cnt = 0;
		for (int i = 0; i < candies.size(); i++) {
			cnt += candies[i] / cnt_candies;
		}
		return cnt;
	}
public:
	long long maximumCandies(std::vector<int>& candies, long long k) {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
      std::cout.tie(nullptr);
		long long l = 1, r = 1e7;
		while(l <= r) {
			long long mid = (r - l) / 2 + l;
			if(can(candies, mid) >= k) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return r;
	}
};

int main() {
	Solution ans;
	std::vector<int> candies = {4, 7, 5};
	std::cout << ans.maximumCandies(candies, 4) << std::endl;
}