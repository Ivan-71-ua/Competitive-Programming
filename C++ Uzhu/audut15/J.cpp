#include <bits/stdc++.h>

#define int long long

const int MAX = 1000000; 
std::vector<bool> primes(MAX + 1, true);
std::vector<int> almostPrimes;

void sieve() {
	primes[0] = primes[1] = false;
	for (int i = 2; i * i <= MAX; ++i) {
		if (primes[i]) {
				for (int j = i * i; j <= MAX; j += i)
					primes[j] = false;
		}
	}
}

void generateAlmostPrimes() {
	for (int i = 2; i <= MAX; ++i) {
		if (primes[i]) {
				int num = i * i;
				while (num <= (int)1e12) {
					almostPrimes.push_back(num);
					num *= i;
				}
		}
	}
	sort(almostPrimes.begin(), almostPrimes.end());
}

int32_t main() {
	sieve();
	generateAlmostPrimes();
	int tests;
	std::cin >> tests;
	while (tests--) {
		int low, high;
		std::cin >> low >> high;
		std::cout << upper_bound(almostPrimes.begin(), almostPrimes.end(), high) -
					upper_bound(almostPrimes.begin(), almostPrimes.end(), low - 1) << "\n";
	}
	
}
