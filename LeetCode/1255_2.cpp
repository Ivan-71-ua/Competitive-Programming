#include <bits/stdc++.h>

class Solution {
	bool can_built(const std::string &wr, std::unordered_map<char, int> &alph) {
		for (char now : wr) {
			if (alph[now] == 0) {
				return false;
			}
			alph[now]--;
		}
		return true;
	}

	void max_score(std::vector<std::string>& words, std::unordered_map<char, int> &alph, std::vector<int>& score, int cur_id, int cur_max, int &ans) {
		if (cur_id >= words.size()) {
			ans = std::max(cur_max, ans);
			return;
		}
		max_score(words, alph, score, cur_id + 1, cur_max, ans);

		bool can_use = true;
		int tmp = 0;
		for (char now : words[cur_id]) {
			if (alph[now] == 0) {
				can_use = false;
			}
			alph[now]--;
			tmp += score[now - 'a'];
		}
		if (can_use) {
			max_score(words, alph, score, cur_id + 1, cur_max + tmp, ans);
		}
		for (char now : words[cur_id]) {
			alph[now]++;
		}
	}

public:
	int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
		std::unordered_map<char, int> alph;
		for (char letter : letters) {
			alph[letter]++;
		}
		int ans = 0;
		max_score(words, alph, score, 0, 0, ans);
		return ans;
	}
};
