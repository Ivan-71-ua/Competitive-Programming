#include <bits/stdc++.h>


class Solution {
public:
	int distributeCandies(std::vector<int>& candyType) {
		std::set<int> warioty(candyType.begin(), candyType.end());
		if(warioty.size() > candyType.size() / 2) {
			return candyType.size() / 2;
		}
		return warioty.size();
	}
};