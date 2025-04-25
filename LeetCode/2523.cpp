
#include <bits/stdc++.h>




class Solution {
public:
	std::vector<int> closestPrimes(int left, int right) {
		std::vector<int> primes;
		std::vector<int> sieve(right + 3, true);
		sieve[1] = false;
		for (long long i = 2; i <= right; i++) {
			if(sieve[i]  && i <= right && i >= left) {
				primes.push_back(i);
			}
			for (long long j = i * i; j <= right; j+= i) {
				sieve[j] = false;
			}
		}
		std::vector<int> ans = {-1, -1};
		int mins = INT32_MAX;
		for (int i = 1; i < primes.size(); i++) {
			if(primes[i] - primes[i - 1] < mins) {
				ans = {primes[i - 1], primes[i]};
				mins = primes[i] - primes[i - 1];
			}
		}
		return ans;
	}
};