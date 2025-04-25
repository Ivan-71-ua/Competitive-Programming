#include <bits/stdc++.h>


class Solution {
public:
   bool isIsomorphic(std::string s, std::string t) {
      std::unordered_map<char,std::vector<int>>m1;
      std::unordered_map<char,std::vector<int>>m2;
      for(int i=0;i<s.length();i++){
         m1[s[i]].push_back(i);
         m2[t[i]].push_back(i);
         if(m1[s[i]]!=m2[t[i]])
            return false;
      }
      return true;
   }
};