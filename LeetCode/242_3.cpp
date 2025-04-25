#include <bits/stdc++.h>

class Solution {
public:
   bool isAnagram(std::string s, std::string t) {
      if(s.size() != t.size()) return false;
		std::vector<int> h(26);
		for(int i = 0; i < s.size(); i++){
			h[s[i] - 'a']++;
		}
      
      for(int i = 0; i < t.size(); i++){
			int x = --h[t[i] - 'a'];
			if(x < 0) {
				return false;
			}
		}
      return true;
   }
};

int main() {
	Solution ans;
	std::string s = "anagram", s1 = "nagaram";
	std::cout << ans.isAnagram(s, s1);
}