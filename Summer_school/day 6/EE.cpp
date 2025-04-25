#include <bits/stdc++.h>


const int MAXN = 1000000;

std::vector<int> sieve() {
	std::vector<int> smallest_prime(MAXN + 1, 0);
	for (int i = 2; i <= MAXN; i++) {
		if (smallest_prime[i] == 0) {
			for (int j = i; j <= MAXN; j += i) {
				if (smallest_prime[j] == 0) {
					smallest_prime[j] = i;
				}
			}
		}
	}
	return smallest_prime;
}

bool check_pairwise_coprime(std::vector<int>& nums, std::vector<int>& smallest_prime) {
	std::vector<int> count(MAXN + 1, 0);
	for (int x : nums) {
		std::set<int> factors;
		while (x > 1) {
			factors.insert(smallest_prime[x]);
			x /= smallest_prime[x];
		}
		for (int f : factors) {
			count[f]++;
			if (count[f] > 1) {
				return false;
			}
		}
	}
	return true;
}

bool check_setwise_coprime(const std::vector<int>& nums) {
	int gcd_all = nums[0];
	for (int x : nums) {
		gcd_all = std::gcd(gcd_all, x);
		if (gcd_all == 1) {
			return true;
		}
	}
	return gcd_all == 1;
}

int32_t main() {
	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> nums[i];
	}
	std::vector<int> smallest_prime = sieve();
	if (check_pairwise_coprime(nums, smallest_prime)) {
		std::cout << "pairwise coprime\n";
	} else if (check_setwise_coprime(nums)) {
		std::cout << "setwise coprime\n";
	} else {
		std::cout << "not coprime\n";
	}
	return 0;
}
