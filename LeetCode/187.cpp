#include <bits/stdc++.h>

class Solution {
public:
   std::vector<std::string> findRepeatedDnaSequences(std::string s) {
		if(s.size() <= 10)
			return {};
		std::unordered_map<std::string, int> DNA_Used;
		std::vector<std::string> ans;
		std::string tp;
		for (int i = 0; i <= s.size() - 10; i++)
		{
			if(i == 0)  {
				tp = s.substr(0, 10);
				DNA_Used[tp]++;
			}
			tp.erase(0, 1);
			tp += s[i + 10];
			DNA_Used[tp]++;
		}
		for(auto now: DNA_Used) {
			if(now.second > 1) ans.push_back(now.first);
		}
		return ans;
	}
};
int main() {
	Solution ans;
	ans.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
}