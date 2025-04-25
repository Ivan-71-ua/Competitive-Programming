#include <bits/stdc++.h>


class Solution {
public:
   std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::vector<std::vector<int>> ans;
		std::unordered_map<int, int> val_quant;
		std::unordered_map<int, int> val_quant2;
		for (auto now: nums1)
		{
			val_quant[now]++;
		}
		for (auto now: nums2)
		{
			val_quant2[now]++;
		}
		nums1.clear();
		for (auto now: val_quant)
		{
			if(!val_quant2.count(now.first)) {
				nums1.push_back(now.first);
			}
		}
		ans.push_back(nums1);
		nums2.clear();
		for (auto now: val_quant2)
		{
			if(!val_quant.count(now.first)) {
				nums2.push_back(now.first);
			}
		}
		ans.push_back(nums2);
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector an{1, 2, 3};
	std::vector an2{2,4,6};
	ans.findDifference(an, an2);
}