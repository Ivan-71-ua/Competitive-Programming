#include <bits/stdc++.h>

/*
sumA - a[i] + b[j] == sumB - b[j] + a[i];
(sumA - sumB) /2 = a[i] - b[j];
a[i] = b[j] + (sumA - sumB);
*/

class Solution {
public:
	std::vector<int> fairCandySwap(std::vector<int>& aliceSizes, std::vector<int>& bobSizes) {
		int sumA = 0;
		int sumB = 0;
		std::unordered_map<int, int> a_i;
		for (auto now: aliceSizes)
		{
			a_i[now]++;
			sumA += now;
		}
		for (auto now : bobSizes)
		{
			sumB += now;
		}
		for (auto now: bobSizes)
		{
			if(a_i.count(now + (sumA - sumB) / 2)) {
				return {now + (sumA - sumB) / 2, now};
			}
		}
		
		return {};
	}
};