#include <bits/stdc++.h>


class Solution {
public:
   bool isPalindrome(std::string s) {
      int i = 0;
      int j = s.size() - 1;
      while (i < j) {
         while (!std::isalnum(s[i]) && i < j) {
            i++;
         }
         while (!std::isalnum(s[j]) && i < j) {
               j--;
         }
         if (std::tolower(s[i]) != std::tolower(s[j])) {
            return false;
         }
         i++;
         j--;
      }
      return true;
   }
};