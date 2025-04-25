#include <bits/stdc++.h>


class Solution {
	bool is_prime(int n) {
		if(n < 2)
			return false;
		for (int i = 2; i * i <=  n; i++)
		{
			if(n % i == 0)
				return false;
		}
		return true;
	}
public:
	bool primeSubOperation(std::vector<int>& nums) {
		int prev = 0;
		for (auto &n: nums)
		{
			int upper = n - prev;
			int largest_p = 0;
			for (int i = upper -1; i > 1; i--)
			{
				if(is_prime(i)) {
					largest_p = i;
					break;
				}
			}
			if(n - largest_p <= prev) {
				return false;
			}
			prev = n - largest_p;
		}
		
		return true;
	}
};