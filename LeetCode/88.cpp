#include <bits/stdc++.h>

class Solution {
public:
   void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		int last = n + m - 1;
		while (n > 0 && m > 0)
		{
			if(nums1[m -1] > nums2[n -1]) {
				nums1[last] = nums1[m - 1];
				m--;
			}
			else {
				nums1[last] = nums2[n - 1];
				n--;
			}
			last--;
		}
		while (n> 0)
		{
			nums1[last] = nums2[n - 1];
			last--;
			n--;
		}
	}
};

int main() {
	Solution ans;
	std::vector<int> nums1{2,2,3,0,0,0};
	int m = 3;
	std::vector<int> nums2{1,5,6};
	int n = 3;
	ans.merge(nums1, n, nums2, m);
}