#include <bits/stdc++.h>


class Solution {
public:
   int maxNumberOfBalloons(std::string text) {
      std::map<char, int> countText;
      std::map<char, int> balloon;
      for(char c: text)
         countText[c]++;
      for(char c: std::string("balloon"))
         balloon[c]++;
      int res = text.length();
      for(const auto &[key, value]: balloon)
         res = std::min(res, countText[key] / value);
      return res;
   }
};