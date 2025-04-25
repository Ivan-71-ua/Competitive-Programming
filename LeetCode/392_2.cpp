#include <bits/stdc++.h>

// Time Complexity is O(N) where n is the size of the target string.
// Space Complexity is O(1)

class Solution {
public:
   bool isSubsequence(std::string s, std::string t) {
      int i = 0 , j = 0;
      while(j < s.size() && i < t.size())
      {
         if(s[j] == t[i])
         j++;
      i++;
      }
      if(j >= s.size()) return true;
      return false;
   }
};