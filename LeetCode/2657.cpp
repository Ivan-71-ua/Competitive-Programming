#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
		std::vector<int> ans(A.size());
		for (int i = 0; i < A.size(); i++)
		{
			std::unordered_map<int, int> res;
			for (int j = 0; j <= i ; j++)
			{
				res[A[j]]++;
			}
			for (int j = 0; j <= i ; j++)
			{
				res[B[j]]++;
			}
			for (auto now: res)
			{
				if(now.second > 1) {
					ans[i]++;
				}
			}
		}
		return ans;
	}
};