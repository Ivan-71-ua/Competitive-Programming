#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::string> findWords(std::vector<std::string>& words) {
		std::vector<std::string> res;
		std::set<char> fir{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
		std::set<char> sec{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
		std::set<char> third{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
		for (int i = 0; i < words.size(); i++)
		{
			std::string k = words[i];
			for (int j = 0; j < k.size(); j++)
			{
				k[j] = std::tolower(k[j]);
			}
			
			std::set<char> tmp(k.begin(), k.end());
			if(std::includes(fir.begin(), fir.end(), tmp.begin(), tmp.end()) || std::includes(sec.begin(), sec.end(), tmp.begin(), tmp.end()) || std::includes(third.begin(), third.end(), tmp.begin(), tmp.end())){
				res.push_back(words[i]);
			}
		}
		return res;
	}
};

int main() {
	Solution ans;
	std::vector<std::string> words{"Hello", "Alaska", "Dad", "Peace"};
	ans.findWords(words);
}