#include <bits/stdc++.h>


class Trie {
	int count;
	Trie *children[26];
public:
	Trie() {
		count = 0;
		std::memset(children, 0, sizeof(children));
	}
	void add(std::string &s, int i) {
		if(i)
			count++;
		if(i == s.size())
			return;
		if(!children[s[i] - 'a'])
			children[s[i] - 'a'] = new Trie();
		children[s[i] - 'a']->add(s, i + 1);
	}
	int get_pref(std::string &s, int i) {
		if(i == s.size()) {
			return count;
		}
		return count + children[s[i] - 'a']->get_pref(s, i + 1);
	}
};

class Solution {

public:
	std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
		Trie *tree = new Trie();
		for (auto &wd: words)
		{
			tree->add(wd, 0);
		}
		int n = words.size();
		std::vector<int> ans(n);
		for (int i = 0; i < n; i++)
		{
			ans[i] = tree->get_pref(words[i], 0);
		}
		return ans;
	}
};