#include <bits/stdc++.h>

class Solution {
long long Comb(int m) {
	long long ans = 0;
	for (int i = 1; i <= m; i++)
	{
		ans += i;
	}
	return ans;
}
public:
   long long zeroFilledSubarray(std::vector<int>& nums) {
		long long an = 0, tp = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if(i == nums.size() - 1 && nums[i] == 0) {
				tp++;
				an += Comb(tp);
				tp = 0;
			} else if(nums[i] == 0) {
				tp++;
			}
			else {
				an += Comb(tp);
				tp = 0;
			}
		}
		return an;
	}
};

int main () {
	Solution ans;
	std::vector<int> aa{0, 0, 0, 2, 0, 0};
	ans.zeroFilledSubarray(aa);
}