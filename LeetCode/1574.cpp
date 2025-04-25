
#include <bits/stdc++.h>



class Solution {
	
public:
	int findLengthOfShortestSubarray(std::vector<int>& arr) {
		int n = arr.size();
		int l = 0;
		while(l + 1 < n && arr[l] <= arr[l + 1])
			l++;
		int res = n - l - 1;
		int r = n - 1;
		while(r - 1 > -1 && arr[r - 1] <= arr[r])
			r--;
		res = std::min(res, r);
		l = 0, r = n - 1;
		while(l < r) {
			while(r < n && l + 1 < r && arr[r - 1] <= arr[r]&& arr[r] >= arr[l]	) {
				r--;
			}
			while(r < n && arr[l] > arr[r]) {
				r++;
			}
			res = std::min(res, r - l - 1);
			if(arr[l	] > arr[l + 1]) break;
			l++;
		}
		return res;
	}
};

int main() {
	std::vector<int> arr{1, 2, 3, 10, 4, 2, 3, 5};
	Solution ans;
	ans.findLengthOfShortestSubarray(arr);
}