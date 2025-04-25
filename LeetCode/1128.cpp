#include <bits/stdc++.h>


class Solution {
public:
	int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
		std::vector<std::vector<int>> dom(10, std::vector<int>(10, 0));
		int ans = 0;
		for (int i = 0; i < dominoes.size(); i++)
		{
			int a = dominoes[i][0];
			int b = dominoes[i][1];
			if(b < a)
				std::swap(a, b);
			dom[a][b] ++;
		}
		for (int i = 1; i < 10; i++)
		{
			for (int j = 1; j < 10; j++)
			{
				if(dom[i][j] > 1)
					ans += dom[i][j] * (dom[i][j] -1) / 2;
			}
		}
		return ans;
	}
};