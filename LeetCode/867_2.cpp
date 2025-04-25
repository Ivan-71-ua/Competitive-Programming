#include <bits/stdc++.h>
static int _ = [](){
      std::cin.tie(0);
      std::cout.tie(0);
      std::ios::sync_with_stdio(false);
      return 0;
   }();

class Solution {
public:
   std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
      int n=matrix.size(), m=matrix[0].size();
      std::vector<std::vector<int>> t(m, std::vector<int>(n));
      for(int i=0; i<n; i++)
         for(int j=0; j<m; j++)
            t[j][i]=matrix[i][j];
      return t;
   }
};