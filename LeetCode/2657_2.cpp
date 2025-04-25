#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
		std::bitset<51> sub_a;
		std::bitset<51> sub_b;
		std::vector<int> res;
		for (int i = 0; i < A.size(); i++)
		{
			sub_a.set(A[i]);
			sub_b.set(B[i]);
			res.push_back((sub_a & sub_b).count());
		}
		return res;
	}
};