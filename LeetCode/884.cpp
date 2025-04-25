#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
		std::vector<std::string> res;
		std::unordered_map<std::string, int> used;
		std::stringstream parse(s1);
		std::string tmp;
		while(parse >> tmp) {
			used[tmp]++;
		}
      parse.clear();
		parse.str(s2);
		while(parse >> tmp) {
			used[tmp]++;
		}
		for (auto now : used)
		{
			if(now.second  == 1) {
				res.push_back(now.first);
			}
		}
		return res;
	}
};

int main() {
	Solution ans;
	ans.uncommonFromSentences("this apple is sweet", "this apple is sour");
}