#include <bits/stdc++.h>


class Solution {
public:
	int distributeCandies(std::vector<int>& candyType) {
		std::unordered_map<int, int> warioty;
		for (int i = 0; i < candyType.size(); i++)
		{
			warioty[candyType[i]]++;
		}
		
		if(warioty.size() > candyType.size() / 2) {
			return candyType.size() / 2;
		}
		return warioty.size();
	}
};