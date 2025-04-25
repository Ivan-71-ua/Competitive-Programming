#include <bits/stdc++.h>

class Solution {
public:
   std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
      std::unordered_map<std::string, std::vector<std::string>> m;
      for (int i = 0; i < strs.size(); i++) {
         std::string key = getKey(strs[i]);
         m[key].push_back(strs[i]);
      }
      
      std::vector<std::vector<std::string>> result;
      for (auto it = m.begin(); it != m.end(); it++) {
         result.push_back(it->second);
      }
      return result;
   }
private:
   std::string getKey(std::string str) {
      std::vector<int> count(26);
      for (int j = 0; j < str.size(); j++) {
         count[str[j] - 'a']++;
      }
      
      std::string key = "";
      for (int i = 0; i < count.size(); i++) {
         key.append(std::to_string(count[i]) + '#');
      }
      return key;
   }
};

int main() {
	Solution ans;
	std::vector<std::string> nums{"eat","tea","tan","ate","nat","bat"};
	ans.groupAnagrams(nums);
}
