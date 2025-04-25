#include <bits/stdc++.h>

class Solution {
public:
   int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
      std::vector<int> xSorted;
      for (const auto& point : points) {
         xSorted.push_back(point[0]);
      }
      sort(xSorted.begin(), xSorted.end());
      int maxWidth = 0;
      for (int i = 0; i < xSorted.size() - 1; i++) {
         maxWidth = std::max(maxWidth, xSorted[i + 1] - xSorted[i]);
      }
      return maxWidth;        
   }
};