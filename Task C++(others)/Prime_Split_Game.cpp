#include <bits/stdc++.h>


const int MAX_N = 2e5 + 5;
std::bitset<MAX_N + 1> isComposite, isWinning, isPrimeLosing, isPrimeWinning, isGoodPosition;

void initialize() {
	isComposite[1] = true;
	for (int i = 2; i <= MAX_N; i++)
		for (int j = 2 * i; j <= MAX_N; j += i)
			isComposite[j] = true;
	for (int i = 3; i <= MAX_N; i += 2) {
		int count = 0, j = i;
		while (!isComposite[j - 2]) {
			count++;
			j -= 2;
		}
		isWinning[i] = count % 2;
		isPrimeLosing[i] = !isComposite[i] && !isWinning[i];
	}
	isWinning[4] = true;
	for (int i = 3; i <= MAX_N; i += 2)
		if (isPrimeLosing[i])
			isWinning |= isPrimeLosing << i;
	for (int i = 1; i <= MAX_N; ++i)
		isPrimeWinning[i] = (i % 2) && isWinning[i] && !isComposite[i];
	for (int i = 3; i <= MAX_N; i += 2)
		if (isPrimeWinning[i])
			isGoodPosition |= isPrimeWinning << i;
}

int main() {
	initialize();
	int t;
	std::cin >> t;
	while(t--) {
		int n, x, totalWinning = 0, totalGood = 0;
		std::cin >> n;
		for (int i = 1; i <= n; ++i) {
			std::cin >> x;
			totalWinning += isWinning[x];
			totalGood += isGoodPosition[x];
		}
		if (totalWinning <= n - n % 2)
			std::cout << (totalWinning ? "Alice" : "Bob") << '\n';
		else
			std::cout << (totalGood && totalGood < n ? "Alice" : "Bob") << '\n';
	}
}