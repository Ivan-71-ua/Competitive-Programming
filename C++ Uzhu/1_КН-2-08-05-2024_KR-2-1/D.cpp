#include <bits/stdc++.h>

const long long MODULO = 1000000007;
const int MAX_SIZE = 1000001;

std::vector<long long> factorial(MAX_SIZE);
std::vector<long long> factorial_inverse(MAX_SIZE);


long long power_mod(long long base, long long exponent, long long modulo) {
	if (exponent == 0) {
		return 1;
	}
	if (exponent % 2 == 0) {
		return power_mod((base * base) % modulo, exponent / 2, modulo);
	}
	return (base * power_mod(base, exponent - 1, modulo)) % modulo;
}


long long modular_inverse(long long x, long long modulo) {
	return power_mod(x, modulo - 2, modulo);
}


long long binomial_coefficient(int n, int k) {
	if (k > n) {
		return 0;
	}
	return ((factorial[n] * factorial_inverse[k]) % MODULO * factorial_inverse[n - k]) % MODULO;
}

long long count_paths(int rows, int columns) {
	return binomial_coefficient(rows + columns, columns);
}

int main() {

	factorial[0] = 1;
	for (int i = 1; i < MAX_SIZE; i++) {
		factorial[i] = (factorial[i - 1] * i) % MODULO;
	}
	factorial_inverse[0] = 1;
	for (int i = 1; i < MAX_SIZE; i++) {
		factorial_inverse[i] = modular_inverse(factorial[i], MODULO);
	}
	int test_cases;
	std::cin >> test_cases;
	while (test_cases--) {
		int n_rows, n_columns, start_row, start_column;
		std::cin >> n_rows >> n_columns >> start_row >> start_column;
		long long result = 0;
		for (int i = 0; i <= n_columns - start_column; i++) {
			 result = (result + count_paths(start_row - 1, i) * count_paths(n_rows - start_row, n_columns - i)) % MODULO;
		}
		std::cout << result << std::endl;
	}
	return 0;
}
