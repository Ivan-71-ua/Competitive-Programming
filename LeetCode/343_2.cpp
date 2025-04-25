#include <bits/stdc++.h>



class Solution {
public:
   int integerBreak(int n) {
		std::vector<int> max_sum1(n + 1, 0);
		for (int i = 1; i < n + 1; i++)
		{
         max_sum1[i] = i;
			for (int last = 1; last < i; last++)
			{
				max_sum1[i] = std::max(max_sum1[i], max_sum1[i - last] * last);
			}
		}
		int res = 0;
		for (int last = 1; last <  n; last++)
		{
			res = std::max(res, max_sum1[n - last] * last);
		}
		return res;
	}
};

int main() {
	Solution ans;
	ans.integerBreak(10);
}