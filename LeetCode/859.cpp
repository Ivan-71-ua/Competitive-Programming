#include <bits/stdc++.h>



class Solution {
public:
	bool buddyStrings(std::string s, std::  string goal) {
		if(s.size() != goal.size())
			return false;
		int dif = 0;
		bool doubles = false;
		std::vector<int> leters(26);
		std::string w1;
		std::string w2;
		for (int i = 0; i < s.size(); i++)
		{
			leters[s[i] - 'a']++;
			if(leters[s[i] - 'a'] > 1)
				doubles = true;
			if(s[i] != goal[i]) {
				dif++;
				if(dif > 2)
					return false;
				w1.push_back(s[i]);
				w2.push_back(goal[i]);
			}
		}
		if(dif == 2) {
			if(w1[0] > w1[1])
				std::swap(w1[0], w1[1]);
			if(w2[0] > w2[1])
				std::swap(w2[0], w2[1]);
			return w1 == w2;
		}
		if(dif == 0) {
			return doubles;
		}
		return false;
	}
};