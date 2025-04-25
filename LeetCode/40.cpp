#include <bits/stdc++.h>


	class Solution {
		std::vector<std::vector<int>> ans;
		std::vector<int> cur_comb;
		int cur_sum = 0;
		
		void comb(int i, std::vector<int>& candidates, int target) {
			if(cur_sum == target) {
				ans.push_back(cur_comb);
				return;
			}
			
			if(cur_sum > target || i >= candidates.size()) {
				return;
			}
			
			for (int j = i; j < candidates.size(); j++) {
				if (j > i && candidates[j] == candidates[j - 1]) continue;
				cur_comb.push_back(candidates[j]);
				cur_sum += candidates[j];
				comb(j + 1, candidates, target);
				cur_comb.pop_back();
				cur_sum -= candidates[j];
			}
		}
		
	public:
		std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
			std::sort(candidates.begin(), candidates.end()); 
			comb(0, candidates, target);
			return ans;
		}
	};


int main() {
	std::vector<int> ss {2,5,2,1,2};
	Solution ans;
	ans.combinationSum2(ss, 8);
}