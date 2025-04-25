#include <bits/stdc++.h>

class Solution {
public:
	int firstUniqChar(std::string s) {
		std::unordered_map<char, int> list;
		for (int i = 0; i < s.size(); i++)
		{
			list[s[i]]++;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if(list[s[i]] == 1)
				return i;
		}
		
		return -1;
	}
};

int main() {
	Solution ans;
	ans.firstUniqChar("tuvwxyzabcdefghijklmnopqrs");
}