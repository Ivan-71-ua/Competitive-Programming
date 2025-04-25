#include <bits/stdc++.h>

class Solution {
	bool can_built(std::string wr, std::map<char, int> alph) {
		for (auto now: wr)
		{
			if(!alph[now]) {
				return false;
			}
			alph[now]--;
		}
		return true;
	}
	void max_score(std::vector<std::string>& words, std::map<char, int> alph, std::vector<int>& score, int cur_id, int cur_max, int &ans) {
		if(cur_id >= words.size()) {
			ans = std::max(cur_max, ans);
			return;
		} 
		int tmp = 0;
		if(can_built(words[cur_id], alph)) {
			for (auto now: words[cur_id])
			{
				alph[now]--;
				tmp += score[now - 'a'];
			}
		}
		max_score(words, alph, score, cur_id + 1, cur_max + tmp, ans);
		if(tmp) {
			for (auto now: words[cur_id])
			{
				alph[now]++;
			}
		}
		max_score(words, alph, score, cur_id + 1, cur_max, ans);
	}
public:
	int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
		std::map<char, int> alph;
		for (int i = 0; i < letters.size(); i++)
		{
			alph[letters[i]]++;
		}
		int ans = 0;
		max_score(words, alph, score, 0, 0, ans);
		return ans;
	}
};