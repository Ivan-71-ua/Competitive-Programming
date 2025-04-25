#include <bits/stdc++.h>


class Solution {
public:
   std::vector<int> countBits(int n) {
		if(n == 0) {
			return {0};
		} if(n == 1) {
			return {0, 1};
		} if(n == 2) {
			return {0, 1, 1};
		} if(n == 3) {
			return {0, 1, 1, 2};
		}
		std::vector<int> ans(n +1);
		ans[0] = 0;
		ans[1] = 1;
		ans[2] = 1;
		ans[3] = 2;
		for (int i = 4; i <= n; i++)
		{
			ans[i] = ans[i % 4] + ans[i >> 2];
		}
		return ans;
	}
};