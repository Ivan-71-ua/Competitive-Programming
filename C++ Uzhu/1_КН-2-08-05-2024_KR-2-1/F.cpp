#include <bits/stdc++.h>
#define int long long

int fac(int n) {
	int res = 1;
	for (int i = 2; i <= n; i++)
	{
		res *= i;
	}
	return res;
}

int32_t main() {
	int n;
	std::cin >> n;
	std::cout << 2 * fac(n - 1) / n;
}