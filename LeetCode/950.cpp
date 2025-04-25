#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
		std::stable_sort(deck.begin(), deck.end());
		std::queue<int> way;
		for (int i = 0; i < deck.size(); i++)
		{
			way.push(i);
		}
		int i = 0;
		std::vector<int> ans(deck.size());
		while(!way.empty()) {
			int id = way.front();
			ans[id] = deck[i];
			way.pop();
			if(!way.empty()) {
				int tmp = way.front();
				way.pop();
				way.push(tmp);
			}
			i++;
		}
		return ans;
	}
};