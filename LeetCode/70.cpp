#include <bits/stdc++.h>


const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
   int climbStairs(int n) {
		std::vector<int> step(n +2);
		step[0] = 1;
		step[1] = 2;
		for (int i = 2; i < n; i++)
		{
			step[i] = step[i - 1] + step[i - 2];
		}
		return step[n - 1];
	}
};