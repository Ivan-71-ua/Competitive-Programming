#include <bits/stdc++.h>
int last_nonzero_digit(long long n) {
	if (n == 0 || n == 1) {
		return 1;
	}

	std::vector<int> base_5_digits;
	long long temp = n;
	while (temp > 0) {
		base_5_digits.push_back(temp % 5);
		temp /= 5;
	}

	long long weighted_sum = 0;
	for (size_t i = 0; i < base_5_digits.size(); ++i) {
		weighted_sum += base_5_digits[i] * i;
	}

	long long even_digit_sum = 0;
	for (int digit : base_5_digits) {
		if (digit % 2 == 0) {
			even_digit_sum += digit;
		}
	}
	long long half_even_sum = even_digit_sum / 2;

	long long total_sum = weighted_sum + half_even_sum;

	int remainder = total_sum % 4;

	int result = std::pow(2, remainder);
	if (result == 1) {
		result = 6; 
	}

	return result;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long n;
	std::cin >> n;

	std::cout << last_nonzero_digit(n) << std::endl;

	return 0;
}
