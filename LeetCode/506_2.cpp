#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
		std::unordered_map<int, int> position_in_list;
		std::unordered_map<int, std::string> plase;
		for (int i = 0; i < score.size(); i++) {
			position_in_list[i] = score[i];
		}
		std::stable_sort(score.begin(), score.end(), std::greater());
		for (int i = 0; i < score.size(); i++)
		{
			if(i == 0) {
				plase[score[i]] = "Gold Medal";
			} else if(i == 1) {
				plase[score[i]] = "Silver Medal";
			} else if(i == 2) {
				plase[score[i]] = "Bronze Medal";
			} else {
				plase[score[i]] = std::to_string(i + 1);
			}
		}
		std::vector<std::string> res;
		for (int i = 0; i < score.size(); i++)
		{
			res.push_back(plase[position_in_list[i]]);
		}
		return res;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{5, 4, 3, 2, 1};
	ans.findRelativeRanks(ss);
}