#include <bits/stdc++.h>


class CombinationIterator {
public:
	std::vector<std::string> comb;
	int it = 0;
	void create(int size, int pos, int len, std::string st, std::string res) {
		if(len == 0) {
			comb.push_back(res);
			return;
		}
		if(pos >= size)
			return;
		res += st[pos];
		create(size, pos + 1, len - 1, st, res);
		res.pop_back();
		create(size, pos + 1, len, st, res);
	}
	CombinationIterator(std::string characters, int combinationLength) {
		create(characters.size(), 0, combinationLength, characters, "");
	}
	std::string next() {
		return comb[it++];
	}
	bool hasNext() {
		return it < comb.size();
	}
};