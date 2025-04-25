#include <bits/stdc++.h>

class Solution {
public:
   bool wordPattern(std::string pattern, std::string s) {
		std::unordered_map<char, std::string> alph_word;
		int point = 0;
		std::set<std::string> used;
		for (int i = 0; i < pattern.size(); i++)
		{
			std::string wd;
			for (; point != s.size(); point++)
			{
				if(s[point] != ' ') {
					wd += s[point];
				}
				
				else break;
			}
			point++;
			if(!alph_word.count(pattern[i]))
				if(!used.count(wd)) {
					alph_word[pattern[i]] = wd;
					used.insert(wd);
				}
			else return false;
			else {
				if(alph_word[pattern[i]] != wd)
					return false;
			}
		}
		if(point -1 != s.size())
				return false;
		return true;
	}
};

int main() {
	Solution ans;
	ans.wordPattern("abba", "dog cat cat dog");
}