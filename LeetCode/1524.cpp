#include <bits/stdc++.h>





class Solution {
	const int MOD = 1e9 + 7;
public:
	int numOfSubarrays(std::vector<int>& arr) {
		int sum = 0, odd = 0, even = 0;
		long long res = 0;
		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i];
			if(sum & 1) {
				res = (res + 1 + even) % MOD;
				odd++;
			} else {
				res += odd;
				even++;
			}
		}
		return res % MOD;
	}
};