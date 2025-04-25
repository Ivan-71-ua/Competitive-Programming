#include <bits/stdc++.h>






class Solution {
	long long power(long long x, long long y, long long p) {
		long long res = 1; 
		x = x % p; 
		if (x == 0) return 0; 
		while (y > 0) {
			if (y & 1) 
				res = (res * x) % p;
			y = y >> 1; 
			x = (x * x) % p; 
		}
		return res;
	}
public:
	int countGoodNumbers(long long n) {
		long long mod = 1e9 + 7;
		long long odd = n / 2;
		long long even = n - odd;
		long long evenCount = power(5, even, mod); 
		long long oddCount = power(4, odd, mod);
		return (evenCount * oddCount) % mod;
	}
};