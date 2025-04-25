#include <bits/stdc++.h>



class Solution {
public:
	void solve(std::vector<int>& candidates, int &sum, std::vector<std::vector<int>> &output, std::vector<int> &ans, int i, int target){
	if(sum==target){
		output.push_back(ans);
		return;
	}
	if(i>=candidates.size() || sum+candidates[i]>target)
		return;
	sum+=candidates[i];
	ans.push_back(candidates[i]);
	solve(candidates, sum, output, ans, i+1, target);
	ans.pop_back();
	sum-=candidates[i];
	while(i+1<candidates.size() && candidates[i]==candidates[i+1] )
		i++;
	solve(candidates, sum, output, ans, i+1, target);
}
	std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)    {
		std::sort(candidates.begin(), candidates.end());
		std::vector<std::vector<int>> output;
		std::vector<int> ans;
		int sum=0;
		solve(candidates, sum,  output,  ans,  0, target);
		return output;
	}
};