#include <bits/stdc++.h>

class Solution {
public:
   int countPalindromicSubsequence(std::string s) {
      std::vector<std::pair<int, int>> v(26, {-1, -1});
      for (int i = 0; i < s.size(); i++) {
         if (v[s[i] - 'a'].first == -1) v[s[i] - 'a'].first = i;
         else v[s[i] - 'a'].second = i;
      }
      int res = 0;
      for (int i = 0; i < 26; i++) {
         if (v[i].second != -1) {
            std::unordered_set<char> tmp;
            for (int j = v[i].first + 1; j < v[i].second; j++) tmp.insert(s[j]);
            res += tmp.size();
         }
      }
      return res;
   }
};
