#include <bits/stdc++.h>


const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
	std::vector<int> selfDividingNumbers(int left, int right) {
		std::vector<int> ans;
		for (int i = left; i <= right; i++)
		{
			bool is = true;
			std::string num = std::to_string(i);
			for (int j = 0; j < num.size(); j++)
			{
				int k = (int)num[j] - 48;
				if((num[j] == '0') || (i % k != 0)) {
					is = false;
					break;
				} 
			}
			if(is) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	ans.selfDividingNumbers(1, 22);
}