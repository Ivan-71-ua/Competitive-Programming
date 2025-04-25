#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
		std::map<int, int> count;
		for (auto num : arr1) {
			count[num]++;
		}

		std::vector<int> ans;


		for (auto num : arr2) {
			while (count[num]) {
					ans.push_back(num);
					count[num]--;
			}
		}

	
		for (auto now : count) {
			while (now.second > 0) {
					ans.push_back(now.first);
					now.second--; 
			}
		}

		return ans;
	}
};
