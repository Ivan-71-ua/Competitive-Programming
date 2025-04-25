#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
		std::vector<int> tmp(score.begin(), score.end());
		std::stable_sort(tmp.begin(), tmp.end(), std::greater());
		std::vector<std::string> res;
		for (int i = 0; i < score.size(); i++)
		{
			int k = std::find(tmp.begin(), tmp.end(), score[i]) - tmp.begin();
			if(k == 0) {
				res.push_back("Gold Medal");
			} else if(k == 1) {
				res.push_back("Silver Medal");
			} else if(k == 2) {
				res.push_back("Bronze Medal");
			} else {
				res.push_back(std::to_string(k +1));
			}
		}
		return res;
	}
};