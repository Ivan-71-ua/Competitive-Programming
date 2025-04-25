#include <bits/stdc++.h>

class Solution {
public:
   std::vector<int> twoSum(std::vector<int>& numbers, int target) {
      int i = 0;
      int j = numbers.size() - 1;
      std::vector<int> result;
      while (i < j) {
         int sum = numbers[i] + numbers[j];
         if (sum < target) {
            i++;
         } else if (sum > target) {
            j--;
         } else {
            result.push_back(i + 1);
            result.push_back(j + 1);
            break;
         }
      }
      
      return result;
   }
};