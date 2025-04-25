#include <bits/stdc++.h>



class Solution {
public:
	std::string kthDistinct(std::vector<std::string>& arr, int k) {
		std::unordered_map<std::string, int> count;
		for (auto st: arr)
		{
			count[st]++;
		}
		for (int i = 0; i < arr.size(); i++)
		{
			if(count[arr[i]] == 1 && k == 1) {
				return arr[i];
			} else if(count[arr[i]] == 1) {
				k--;
			}
		}
		return "";
	}
};