#include <bits/stdc++.h>



class Solution {
public:
	bool buddyStrings(std::string s, std::string goal) {
		if(s.size()!=goal.size())
			return false;
		if(s==goal) {
			std::set<char> tmp(s.begin(), s.end());
			return tmp.size()<goal.size();
		}
		int i = 0, j = s.size()-1;
		while(i<j&&s[i]==goal[i])
			i++;
		while(j>=0&&s[j]==goal[j])
			j--;
		if(i<j) {
			std::swap(s[i], s[j]);
		}
		return s==goal;
	}
};