#include <bits/stdc++.h>
#define int long long


int brute_force(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i / (n / std::gcd(n, i));
	}
	return sum;
}

int32_t main() {
	
	int n;
	std::cin >> n;
	std::cout << brute_force(n) << "\n";
	return 0;
}
