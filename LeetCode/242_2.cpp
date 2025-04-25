#include <bits/stdc++.h>

class Solution {
public:
   bool isAnagram(std::string s, std::string t) {
      if(s.size() != t.size()) return false;
      std::unordered_map<char,int> smap;
      std::unordered_map<char,int> tmap;
      for(int i = 0; i < s.size(); i++){
         smap[s[i]]++;
         tmap[t[i]]++;
      }
      
      for(int i = 0; i < smap.size(); i++){
         int a = smap[i], b = tmap[i];
         if(smap[i] != tmap[i]) return false;
      }
      return true;
   }
};

int main() {
	Solution ans;
	std::string s = "anagram", s1 = "nagaram";
	std::cout << ans.isAnagram(s, s1);
}