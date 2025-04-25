#include <bits/stdc++.h>

class Solution {
public:
   std::vector<int> findAnagrams(std::string s, std::string p) {
		std::unordered_map<char, int> quant_of_p;
		for (int i = 0; i < p.size(); i++)
		{
			quant_of_p[p[i]]++;
		}
		std::vector<int> ans;
		std::unordered_map<char, int> quant_of_s;
		for (int i = 0; i <= s.size(); i++)
		{
			if(i > (p.size() - 1)) {
				bool is_pal = true;
				for (auto now: quant_of_p)
				{
					if(quant_of_s.count(now.first)) {
						if(now.second != quant_of_s[now.first]) {
							is_pal = false;
							break;
						}
					} else {
						is_pal = false;
						break;
					}
				}
				if(is_pal)
					ans.push_back(i - (p.size()));
				quant_of_s[s[i - p.size()]]--;
				quant_of_s[s[i]]++;
			} else {
				quant_of_s[s[i]]++;
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	ans.findAnagrams("abab", "ab");
}