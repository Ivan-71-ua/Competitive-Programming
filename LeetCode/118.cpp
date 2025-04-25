#include <bits/stdc++.h>


class Solution {
public:
   std::vector<std::vector<int>> generate(int numRows) {
		std::vector<std::vector<int>> val(numRows);
		for (int i = 0; i < numRows; i++)
		{
			std::vector<int> ans(i +1);
			for (int j = 0; j <= i; j++)
			{
				if(j == 0 || j == i)
					ans[j] = 1;
				else {
					ans[j] = val[i - 1][j - 1] + val[i - 1][j];
				}
			}
			val[i] = ans;
		}
		return val;
	}
};

int main() {
	Solution ans;
	ans.generate(3);
}