#include <bits/stdc++.h>
#define int long long

int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}


int32_t main() {
	int n;
	int res = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		res += phi(i);
	}
	std::cout << res;
}