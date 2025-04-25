#include <bits/stdc++.h>
#define int long long


int32_t main() {
	int n;
	std::cin >> n;

	std::vector<int> res(n + 1);
	n >= 1 ? res[1] = 1 : 0;
	n >= 2 ? res[2] = 2 : 0;
	for (int i = 3; i <= n; i++)
	{
		res[i] = (res[i - 1] + (i - 1) * res[i - 2]) % 1000000007;
	}
	std::cout << res[n];
}