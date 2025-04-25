#include <bits/stdc++.h>


class NumArray {
public:
		std::vector<int> prefixSum;
		NumArray(std::vector<int>& nums) {
			int count=0;
			for(int i=0;i<nums.size();i++){
					count+=nums[i];
					prefixSum.push_back(count);
			}
		}
		
		int sumRange(int left, int right) {
			int answer=prefixSum[right];
			if(left-1>=0){
					answer-=prefixSum[left-1];
			}
			return answer;
		}
};
