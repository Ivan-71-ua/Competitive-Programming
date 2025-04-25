#include <bits/stdc++.h>


class Solution {
   int calcut(std::unordered_map<char, int> &alph) {
      int res = 0;
      for (auto &&i : alph)
      {
         res += i.second;
      }
      return res;
   }
public:
   int lengthOfLongestSubstring(std::string s) {
      int res = 0;
      std::unordered_map<char, int> alph;
      int l = 0;
      for (int i = 0; i < s.size(); i++)
      {
         char k = s[i];
         if(alph[k]) {
            while(l < i) {
               char tmp = s[l++];
               alph[tmp]--;
               if(tmp == k) break;
               
            }
         }
         alph[k]++;
         res = std::max(res, calcut(alph));
      }
      return res;
   }
};


int main() {
   Solution ans;
   ans.lengthOfLongestSubstring("dvdf");
}