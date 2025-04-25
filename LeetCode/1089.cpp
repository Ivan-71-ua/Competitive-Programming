#include <bits/stdc++.h>


class Solution {
public:
	void duplicateZeros(std::vector<int>& arr) {
		int n = arr.size();
		std::vector<int> ans(n);
		int i = 0, j = 0;
		while(i < n && j < n) {
			if(arr[j] != 0) {
				ans[i] = arr[j];
			}else {
				i++;
			}
			i++;
			j++;
		}
		arr = ans;
	}
};