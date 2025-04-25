#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long sum_of_remainders(long long n) {
	long long result = 0;
	long long sqrt_n = sqrt(n);

	// Обчислюємо залишки для малих значень i
	for (long long i = 1; i <= sqrt_n; ++i) {
		result = (result + n % (i * i)) % MOD;
	}

	// Обчислюємо залишки для великих значень i
	for (long long k = 1; k <= sqrt_n; ++k) {
		long long left = n / (k + 1);
		long long right = n / k;
		long long sum_of_squares = (k * k % MOD) * ((right - left) % MOD) % MOD;
		result = (result + sum_of_squares) % MOD;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;
		cout << sum_of_remainders(n) << "\n";
	}

	return 0;
}
