#include <bits/stdc++.h>

class Solution {
public:
	int maxNumberOfBalloons(std::string text) {
		std::unordered_map<char, int> char_quant;
		char_quant['b'] = 0;
		char_quant['a'] = 0;
		char_quant['l'] = 0;
		char_quant['o'] = 0;
		char_quant['n'] = 0;
		for (int i = 0; i < text.size(); i++)
		{
			if(char_quant.count(text[i]))
				char_quant[text[i]]++;
		}
		int min = 10000;
		for (auto it = char_quant.begin(); it != char_quant.end(); it++)
		{
			if (it->first == 'l' || it->first ==  'o') {
				if(it->second / 2 < min)
					min = it->second / 2;
			}
			else {
				if(it->second < min)
					min = it->second;
			}
		}
		return min;
	}
};

int main()  {
	Solution ans;
	ans.maxNumberOfBalloons("balon");
}