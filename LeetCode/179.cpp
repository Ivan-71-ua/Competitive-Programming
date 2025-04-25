#include <bits/stdc++.h>

class Solution {
public:
   // to check which should come first
   // see that by adding in which way gives bigger number
   static bool mysort(std::string a, std::string b){
      return a+b > b+a;
	}
   std::string largestNumber(std::vector<int>& nums) {
      std::string s = "";
      std::vector<std::string> all_numbers;
      // convert every number to string
      for(int it: nums){
         all_numbers.push_back(std::to_string(it));
      }
      // sort accoring to custom sort function
      std::sort(all_numbers.begin(),all_numbers.end(),mysort);
      if(all_numbers[0]=="0"){
         return "0";
      }
      
      for(std::string a: all_numbers){
         s += a;
      }
      return s;
   }
};

int main() {
	Solution ans;
	std::vector<int> nums{3, 30, 34, 5, 9};
	ans.largestNumber(nums);
}