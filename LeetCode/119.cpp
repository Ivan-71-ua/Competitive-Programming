#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> getRow(int rowIndex)
	{
		std::vector<std::vector<int>> pascal;
		pascal.push_back({1});
		pascal.push_back({1, 1});
		for (int i = 2; i < rowIndex + 1; i++)
		{
			std::vector<int> tmp;
			tmp.push_back(1);
			int k = 1;
			while(k < i) {
				tmp.push_back(pascal[i - 1][k] + pascal[i - 1][k - 1]);
				k++;
			}
			tmp.push_back(1);
			pascal.push_back(tmp);
		}
		return pascal[rowIndex];
	}
};

int main() {
	Solution ans;
	ans.getRow(3);
}