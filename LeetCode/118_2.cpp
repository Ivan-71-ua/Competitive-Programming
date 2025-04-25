#include <bits/stdc++.h>


class Solution {
public:
   std::vector<std::vector<int>> generate(int numRows)
   {
      std::vector<std::vector<int>> ret;
      for(int i = 0; i < numRows ; i++){
         std::vector<int> row(i+1, 1);
         for(int j = 1; j < i ; j++){
            row[j] = ret[i-1][j] + ret[i-1][j-1];
         }
         ret.push_back(row);
      }
      return ret;
   }
};