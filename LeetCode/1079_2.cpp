#include <bits/stdc++.h>


class Solution {
public:
	void DFS(std::unordered_map<char, int>& freq, int& cnt) {
		for (auto& fr : freq) {
			if (fr.second > 0) {
				cnt++;
				fr.second--;
				DFS(freq, cnt);
				fr.second++;  
			}
		}
	}

	int numTilePossibilities(std::string tiles) {
		std::unordered_map<char, int> freq;
		for (char ch : tiles) {
			freq[ch]++;
		}
		int cnt = 0;
		DFS(freq, cnt);
		return cnt;
	}
};