#include <bits/stdc++.h>


class Solution {
public:
	bool isAlienSorted(std::vector<std::string> &words, std::string order)
	{
		std::map<char, int> weight;
		for (int i = 0; i < order.size(); i++)
		{
			weight[order[i]] = i;
		}
		for (int i = 1; i < words.size(); i++)
		{
			int lng = std::min(words[i - 1].size(), words[i].size());
			int j;
			for (j = 0; j < lng; j++)
			{
				if(weight[words[i -1][j]] < weight[words[i][j]]) {
					break;
				} else if(weight[words[i -1][j]] > weight[words[i][j]])
					return false;
			}
			if(j == lng && words[i -1].length() > words[i].length())
				return false;
		}
		return true;
	}
};