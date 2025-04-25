#include <bits/stdc++.h>

const long long MAX_VAL = 1000000, MOD = 998244353;

long long mod_pow(long long base, long long exp, long long mod = MOD) {
	if (exp == 0)
		return 1;
	long long half = mod_pow(base, exp / 2, mod);
	if (exp % 2)
		return half * half % mod * base % mod;
	return half * half % mod;
}

long long prime_count = 0;
std::vector<long long> primes(MAX_VAL + 5, 0), mobius(MAX_VAL + 5, 0);
std::vector<long long> f(MAX_VAL + 5, 0), total(MAX_VAL + 5, 0);
std::vector<bool> is_prime(MAX_VAL + 5, false);

void preprocess() {
	is_prime[0] = is_prime[1] = true;
	mobius[1] = 1;
	for (long long i = 2; i <= MAX_VAL; i++) {
		if (!is_prime[i]) {
			prime_count++;
			primes[prime_count] = i;
			mobius[i] = -1;
		}
		for (long long j = 1; j <= prime_count && i * primes[j] <= MAX_VAL; j++) {
			is_prime[i * primes[j]] = true;
			if (i % primes[j] == 0)
				break;
			mobius[i * primes[j]] = -mobius[i];
		}
	}
	for (long long i = 1; i <= MAX_VAL; i++) {
		for (long long j = i; j <= MAX_VAL; j += i)
			f[j] = (f[j] + mobius[i] * i) % MOD;
		f[i] = (f[i] + MOD) % MOD;
	}
}

int32_t main() {
	preprocess();
	long long n;
	std::cin >> n;
	long long ans = 0;
	for (int i = 1, x; i <= n; i++) {
		std::cin >> x;
		ans = (ans - x + MOD) % MOD;
		total[x]++;
	}
	for (long long i = 1; i <= MAX_VAL; i++) {
		long long p = 0;
		for (long long j = i; j <= MAX_VAL; j += i)
			p = (p + total[j] * (j / i) % MOD) % MOD;
		ans = (ans + p * p % MOD * i % MOD * f[i] % MOD) % MOD;
	}
	std::cout << ans * mod_pow(2, MOD - 2, MOD) % MOD << '\n';
	return 0;
}
