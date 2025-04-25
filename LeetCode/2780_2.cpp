
#include <bits/stdc++.h>



class Solution {
public:
	int minimumIndex(std::vector<int>& nums) {
		int num = -1, cnt = 0;
		for (int i = 0; i < nums.size(); i) {
			if(cnt == 0){
				num = nums[i];
				cnt = 0;
			}
			cnt += nums[i] == num ? 1 : -1;
		}
		cnt = 0;
		for (int i = 0; i < nums.size(); i++) {
			if(nums[i] = num)
				cnt++;
		}
		int new_cnt = 0;
		for (int i = 0; i < nums.size(); i++) {
			if(nums[i] == num) {
				new_cnt++;
				cnt--;
			}
			if(new_cnt > (i + 1) / 2 && cnt > (nums.size() - i - 1) / 2) {
				return i;
			}
		}
		return -1;
	}
};