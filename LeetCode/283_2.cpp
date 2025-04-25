#include <bits/stdc++.h>

class Solution {
public:
   void moveZeroes(std::vector<int>& nums) {
		int l = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != 0) {
				std::swap(nums[i], nums[l]);
				l++;
			}
		}
		
	}
};

int main(){
	Solution ans;
	std::vector<int> ss{0, 1, 0, 3, 12};
	ans.moveZeroes(ss);
}