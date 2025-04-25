#include <bits/stdc++.h>


class Solution {
public:
	std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
		std::vector<bool> res(l.size());
		for (int i = 0; i < l.size(); i++)
		{
			std::vector<int> tmp = nums;
			std::stable_sort(tmp.begin() + l[i], tmp.begin() + r[i] + 1);
			bool is = true;
			int add = tmp[l[i] + 1] - tmp[l[i]];
			for (int j = l[i] + 2; j <= r[i]; j++)
			{
				if(tmp[j] - tmp[j - 1] != add) {
					is = false;
					break;
				}
			}
			res[i] = is;
		}
		return res;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{4, 6, 5, 9, 3, 7};
	std::vector<int> kk{0, 0, 2};
	std::vector<int> dd{2, 3, 5};
	ans.checkArithmeticSubarrays(ss, kk, dd);
}