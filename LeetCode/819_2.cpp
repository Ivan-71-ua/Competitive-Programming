#include <bits/stdc++.h>


class Solution {
public:
std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
	std::string ans;
	int maxCount = 0;
	std::unordered_map<std::string, int> count;
	std::unordered_set<std::string> bannedSet{banned.begin(), banned.end()};

	// Make the paragraph lowercased and remove all the punctuations.
	for (char& c : paragraph)
		c = isalpha(c) ? tolower(c) : ' ';

	std::istringstream iss(paragraph);

	for (std::string word; iss >> word;)
		if (!bannedSet.count(word))
		++count[word];

	for (const auto& [word, freq] : count)
		if (freq > maxCount) {
		maxCount = freq;
		ans = word;
		}

	return ans;
}
};