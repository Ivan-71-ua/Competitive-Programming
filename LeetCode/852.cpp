#include <bits/stdc++.h>



class Solution {
public:
	int peakIndexInMountainArray(std::vector<int>& arr) {
		int l = 0, r = arr.size() - 1, m;
		while (l < r) 
		{
			m = l + (r - l) / 2;
			if(arr[m] > arr[m + 1]) {
				r = m	;
			} else {
				l = m + 1;
			} 
		}
		return r;
	}
};


int main() {
	std::vector<int> ss{3,5,3,2,0};
	Solution ans;
	ans.peakIndexInMountainArray(ss);
}