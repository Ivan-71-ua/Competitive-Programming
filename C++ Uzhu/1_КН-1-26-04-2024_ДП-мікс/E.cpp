#include <bits/stdc++.h>

const int MAX_LIMIT = 5000001;

std::vector<int> digitPowers(10), memo(MAX_LIMIT, 0);
long long totalResult;

int DigitPowerSum(int number) {
	int powerSum = 0;
	while (number) {
		powerSum += digitPowers[number % 10];
		number /= 10;
	}
	return powerSum;
}

int Search(int number) {
	if (memo[number] > 0) return memo[number];
	if (memo[number] == 0) memo[number] = -1;
	else if (memo[number] == -1) memo[number] = number;
	return memo[number] = std::min(number, Search(DigitPowerSum(number)));
}

long long TotalHappiness(int start, int end, int exponent) {
	long long happinessSum = 0;
	for (int i = 0; i < 10; i++) {
		int product = 1;
		for (int j = 0; j < exponent; j++) product *= i;
		digitPowers[i] = product;
	}
	for (int i = start; i <= end; i++) {
		happinessSum += Search(i);
	}
	return happinessSum;
}

int main() {
	int startRange, endRange, exponent;
	while (std::cin >> startRange >> endRange >> exponent) {
		std::fill(memo.begin(), memo.end(), 0);
		totalResult = TotalHappiness(startRange, endRange, exponent);
		std::cout << totalResult << std::endl;
	}
}
