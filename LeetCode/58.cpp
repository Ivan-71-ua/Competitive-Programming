#include <bits/stdc++.h>

class Solution {
public:
   int lengthOfLastWord(std::string s) {
		int k = 0;
		bool word = false;
		for (int i = s.size() -1;i >= 0 ; i--)
		{
			if(s[i] == ' ') {
				word = false;
				if(k > 0) break;
			}
			if(isalpha(s[i])) {
				word = true;
			}
			if(isalpha(s[i]) && word)  {
				k++;
			}
			
		}
		return k;
	}
};

int main() {
	Solution ans;
	ans.lengthOfLastWord("   fly me   to   the moon  ");
}