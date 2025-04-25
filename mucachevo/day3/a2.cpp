#include <bits/stdc++.h>

std::mt19937 rng(228);

int randint(int l, int r) {
	return std::uniform_int_distribution<int>(l, r)(rng);
}

void max_candies_randomized() {
	long long n, g;
	std::cin >> n >> g;
	std::vector<long long> candies(n);
	for (long long i = 0; i < n; i++) {
		std::cin >> candies[i];
	}
	if(n == 1) {
		std::cout << 1;
		return;
	}
	long long max_count = 1;
	for (int iteration = 0; iteration < 20; iteration++) {
		long long a = randint(0, n - 1);
		long long b = randint(0, n - 1);
		while(a == b) b = randint(0, n - 1);

		long long diff = std::abs(candies[a] - candies[b]);

		std::set<long long> divisors;
		
		if (diff % 2 == 0) {
			divisors.insert(2);
			while (diff % 2 == 0) {
				diff /= 2;
			}
		}
		for (long long i = 3; i * i <= diff; i += 2) {
			if (diff % i == 0) {
				divisors.insert(i);
				while (diff % i == 0) {
					diff /= i;
				}
			}
		}
		if (diff > 1) {
			divisors.insert(diff);
		}
		for(auto &k : divisors) {
			std::map<int, long long> cnt;
			for(auto &v : candies) {
				cnt[v % k]++;
			}
			for(auto &v : cnt) {
				max_count = std::max(max_count, v.second);
			}
		}
	}
	std::cout << max_count << "\n";
}

int main() {
	max_candies_randomized();
	return 0;
}
