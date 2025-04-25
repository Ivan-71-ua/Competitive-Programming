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
	//std::vector<std::map<int, int>> candy_positions;
	long long max_count = 0;

	for (int iteration = 0; iteration < 50; iteration++) {
		long long a = randint(0, n - 1);
		long long b = randint(0, n - 1);
		int n = abs(candies[a] - candies[b]);
		std::set<long long> cur;
		if (n % 2 == 0) {
			cur.insert(2);
			while (n % 2 == 0) {
				n /= 2;
			}
		}
		for (long long i = 3; i * i <= n; i += 2) {
			if (n % i == 0) {
				cur.insert(i);
				while (n % i == 0) {
					n /= i;
				}
			}
		}

		if (n > 1) {
			cur.insert(n);
		}
		
		for(auto &k : cur) {
			std::unordered_map<int, long long> ost;
			for(auto &v : candies) {
				ost[v % k]++;
			}
			for(auto m: ost) {
				max_count = std::max(max_count, m.second);
			}
		}
	}
	std::cout << max_count;
}

int main() {
	max_candies_randomized();
	return 0;
}
