#include <bits/stdc++.h>


class Solution {
public:
	int findLengthOfLCIS(std::vector<int>& nums) {
		int start = nums[0];
		int answer = 1, count = 1;
		for(int i = 1; i < nums.size(); i++){
				if(nums[i] > start){
					start = nums[i];
					count++;
				}
				else{
					start = nums[i];
					count = 1;
				}
			answer = std::max(answer, count);
		}
		return answer;
	}
};