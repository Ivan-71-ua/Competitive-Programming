#include <bits/stdc++.h>

class Solution {
public:
	int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers) {
		std::sort(players.begin(), players.end());
		std::sort(trainers.begin(), trainers.end());
		int cnt = 0;
		int i = 0, j = 0;
		while(i < players.size() && j < trainers.size()) {
			if(players[i] <= trainers[j]) {
				cnt++;
				i++;
				j++;
			} else{
				j++;
			}
		}
		return cnt;
	}
};