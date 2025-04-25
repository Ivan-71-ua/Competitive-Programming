
#include <bits/stdc++.h>


class Solution {
public:
	int isPrefixOfWord(std::string sentence, std::string searchWord) {
		std::stringstream parse(sentence);
		int idx = 1;
		while(parse >> sentence) {	
			if(sentence.find(searchWord) == 0) {
				return idx;
			}
			idx++;
		}
		return -1;
	}
};


int main() {
	Solution ans;
	ans.isPrefixOfWord("hellohello hellohellohello", "ell");
}