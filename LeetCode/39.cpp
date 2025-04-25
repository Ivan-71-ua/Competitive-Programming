#include <bits/stdc++.h>


class Solution {
	std::vector<std::vector<int>> ans;
	std::vector<int> cur;
	void all_comb(int j, std::vector<int>& candidates, int target) {
		if(target == 0) {  
			ans.push_back(cur);
			return;
		}
		for (int i = j; i < candidates.size(); i++)
		{
			if(candidates[i] > target) {
				continue; // Пропустити поточний елемент, якщо він більший за залишок target
			}
			cur.push_back(candidates[i]);  
			all_comb(i, candidates, target - candidates[i]); 
			cur.pop_back(); 
		}
	}
public:
	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
		all_comb(0, candidates, target); 
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<int> dd{8,7,4,3};
	ans.combinationSum(dd, 11);
}