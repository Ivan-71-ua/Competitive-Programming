#include <bits/stdc++.h>


class CombinationIterator {
	std::map<std::string, int> comb;
	std::map<std::string, int>::iterator ptr;
public:
	CombinationIterator(std::string characters, int combinationLength) {
		int mask = 1 << characters.size();
		for (int i = 1; i < mask; i++)
		{
			std::string st;
			int j = 0;
			int cur = i;
			while(cur) {
				if(cur&1) {
					st += characters[j];
				}
				j++;
				cur >>= 1;
			}
			if(st.size() == combinationLength) {
				comb[st]++;
			}
		}
		ptr = comb.begin();
	}
	
	std::string next() {
		auto now = ptr;
		ptr++;
		return now->first;
	}
	
	bool hasNext() {
		return ptr != comb.end();
	}
};