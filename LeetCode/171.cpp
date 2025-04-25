#include <bits/stdc++.h>


	class Solution {
	public:
		int titleToNumber(std::string columnTitle) {
			long long res = 0;
			for (int i = 0; i < columnTitle.size(); i++)
			{
				res += ((columnTitle[i] - 'A') + 1) * pow(26, columnTitle.size() - i -1);
			}
			return res;
		}
	};


int main() {
	Solution ans;
	ans.titleToNumber("ZY");
}

