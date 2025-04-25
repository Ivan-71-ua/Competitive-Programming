#include <bits/stdc++.h>


class Solution {
public:
	bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
		if(sentence2.size() < sentence1.size())
			std::swap(sentence1, sentence2);
		std::stringstream parse(sentence2);
		std::vector<std::string> a;
		std::vector<std::string> b;
		while(parse >> sentence2) {
			b.push_back(sentence2);
		}
		parse.clear();
		parse.str(sentence1);
		while(parse >> sentence1) {
			a.push_back(sentence1);
		}
		int l1 = 0, l2 = 0;
		while(l1 < a.size() && l2 < b.size() && a[l1] == b[l2]) {
			l1++;
			l2++;
		}
		int r1 = a.size() - 1, r2 = b.size() - 1;
		while(r1 > -1 && r2 > -1 && a[r1] == b[r2]) {
			r1--;
			r2--;
		}
		return l1 > r1;
	}
};