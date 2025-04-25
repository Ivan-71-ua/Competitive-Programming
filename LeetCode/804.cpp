#include <bits/stdc++.h>


class Solution {
public:
	int uniqueMorseRepresentations(std::vector<std::string>& words) {
		std::vector<std::string> morze{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
		std::unordered_set<std::string> res;
		for (int i = 0; i < words.size(); i++)
		{
			std::string cover;
			for (auto letter : words[i])
			{
				cover += morze[letter - 'a'];
			}
			res.insert(cover);
		}
		return res.size();
	}
};