#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
		int less = 0;
		int greater = nums.size() - 1;
		//int equale = 0;
		std::vector<int> ans(nums.size());
		
		for (int i = 0, j = nums.size() - 1;i < nums.size(); i++, j--)
		{
			if(nums[i] < pivot) {
				ans[less] = nums[i];
				less++;
			} if (nums[j] > pivot) {
				ans[greater] = nums[j];
				greater--;
			} 
			//else {
				//equale++;
			//}
		}
		while(less <= greater) {
			ans[less] = pivot;
			less++;
		}
		return ans;
	}
};
int main() {
	Solution ans;
	std::vector<int> ss{9, 12, 5, 10, 14, 3, 10};
	ans.pivotArray(ss,10);
}