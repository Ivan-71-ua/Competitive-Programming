#include <bits/stdc++.h>

// Time Complexity: O(m + n), we check each element of nums1Set and nums2Set
// Space Complexity: O(m + n), where m and n are length sets in worst case.

class Solution
{
public:
   std::vector<std::vector<int>> findDifference(std::vector<int> &nums1, std::vector<int> &nums2)
   {
      std::unordered_set<int> nums1Set(nums1.begin(), nums1.end());
      std::unordered_set<int> nums2Set(nums2.begin(), nums2.end());
      std::vector<int> lst1;
      std::vector<int> lst2;
      for (const auto &num : nums1Set)
      {
         if (nums2Set.find(num) == nums2Set.end())
         {
            lst1.push_back(num);
         }
      }
      for (const auto &num : nums2Set)
      {
         if (nums1Set.find(num) == nums1Set.end())
         {
            lst2.push_back(num);
         }
      }
      return {lst1, lst2};
   }
};