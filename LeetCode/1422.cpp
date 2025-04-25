#include <bits/stdc++.h>

const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
   int maxScore(std::string s) {
		int one = 0, zero =0, ans = 0;
		if(s[0] == '0')
			zero++;
		for (int i = s.size() - 1; i >= 1; i--)
		{
			if(s[i] == '1')
				one++;
		}
		ans = zero + one;
		
		for (int i = 1; i <= s.size() -2; i++)
		{
			if (s[i] == '1')
			{
				one--;
				ans = std::max(ans, one + zero);
			}
			else if(s[i] == '0') {
				zero++;
				ans = std::max(ans, one + zero);
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::string s = "01001";
	ans.maxScore(s);
}