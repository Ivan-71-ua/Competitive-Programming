	#include <bits/stdc++.h>



	class Solution {
	public:
		std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
			std::vector<std::vector<std::string>> val;
			std::unordered_map<int, std::vector<std::string>> word_val;
			int arr_char[26] {-298256, 9432145, 5575034, -52143, 44989, 235862, -3178345, 875687, -919674, 1771347, 
									7778153, 1111911, 17184233, 13566789, -4356285, 126950, 661246, 97897, -334533, -56896,
									-6786434, 5152367, -1379545, -183156, -20121087, 32587434};
			int m = strs.size();
			for (int i = 0; i < m; i++)
			{
				int sum = 0;
				for (int j = 0; j < strs[i].size(); j++)
				{
					sum += arr_char[(int)strs[i][j] - 97];
				}
				if(word_val.count(sum)) {
					word_val[sum].push_back(strs[i]);
				}
				else {
					word_val[sum] = {strs[i]};
				}
			}
			for (auto it = word_val.begin(); it != 0; it++)
			{
				val.push_back(it->second);
			}
			return val;
			}
	};

int main() {
	Solution ans;
	std::vector<std::string> nums{"eat","tea","tan","ate","nat","bat"};
	ans.groupAnagrams(nums);
}