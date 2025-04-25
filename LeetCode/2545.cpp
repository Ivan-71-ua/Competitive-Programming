


#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::vector<int>> sortTheStudents(std::vector<std::vector<int>>& score, int k) {
		std::stable_sort(score.begin(), score.end(), [k](const std::vector<int>& score1, const std::vector<int>& score2) {
			return score1[k] > score2[k];
		});
		return score;
	}
};
