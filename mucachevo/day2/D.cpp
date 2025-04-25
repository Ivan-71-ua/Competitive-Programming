#include <bits/stdc++.h>

const long long MOD = 1e9 + 7;
const long long P = 31;

long long count_distinct_substrings(const std::string &s) {
	long long n = s.size();
	std::set<long long> substr_hashes;
	std::vector<long long> p_pow(n);
	p_pow[0] = 1;
	for (long long i = 1; i < n; i++) {
		p_pow[i] = (p_pow[i - 1] * P) % MOD;
	}
	for (long long i = 0; i < n; i++) {
		long long current_hash = 0;
		for (long long j = i; j < n; j++) {
			current_hash = (current_hash * P + (s[j] - 'a' + 1)) % MOD;
			substr_hashes.insert(current_hash);
		}
	}
	return substr_hashes.size();
}

int main() {
	std::string s;
	std::cin >> s;
	std::cout << count_distinct_substrings(s) << "\n";
	return 0;
}
