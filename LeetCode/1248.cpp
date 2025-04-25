#include <bits/stdc++.h>


class Solution {
	int get_count(std::vector<int> pref, int i, int j) {
		if(i > 0) {
			return pref[j] - pref[i - 1];
		}
		return pref[j];
	}
public:
	int numberOfSubarrays(std::vector<int>& nums, int k) {
		int n = nums.size();
		int even = 0;
		int count = 0;
		for (int i =0, j = 0, m = 0; i < n; i++)
		{
			even += nums[i] & 1;
			while(even > k) {
				even -= nums[j] & 1;
				j++;
				m = j;
			}
			if(even == k) {
				while(!(nums[m] & 1)) {
					m++;
				}
				count += (m - j) +1;
			}
		}
		return count;
	}
};