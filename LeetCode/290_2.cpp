#include <bits/stdc++.h>


class Solution {
   
public:
   bool wordPattern(std::string pattern, std::string str) {
      std::vector<int> pat_map (26, 0);
      std::unordered_map<std::string,int> str_map;
      int i=0, n = pattern.size();
      std::istringstream ss (str);
      std::string token;
      
      for(std::string token; ss >> token; ++i) {
         if(i == n || pat_map[pattern[i]-'a'] != str_map[token]) return false;
         
         // 1-based indexing since map assigns 0 as a default value for keys not found.
         pat_map[pattern[i]-'a'] = str_map[token] = i+1;
      }
      return i == n;
   }
};
