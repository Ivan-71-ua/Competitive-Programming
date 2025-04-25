#include <bits/stdc++.h>

class Solution {
public:
   int countPalindromicSubsequence(std::string s) {
		std::vector<char> used;
		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (!std::count(used.begin(), used.end(), s[i])) {
				int first = i, last = -1;
				for (int j = 0; j < s.size(); j++)
				{
					if(s[j] == s[i])
						last = j;
				}
				if(first == last) continue;
				std::set<char> diferent;
				for (int c = first + 1; c < last; c++)
				{
					diferent.insert(s[c]);
				}
				used.push_back(s[i]);
				ans += diferent.size();
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	ans.countPalindromicSubsequence("bbcbaba");
}