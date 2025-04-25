#include <bits/stdc++.h>
#define int long long


int32_t main() {
	int n, a, b;
	std::cin >> n >> a >> b;
	if(a < b)
		std::swap(a, b);
	if(n % 2 == 0)
		std::cout << (a + b) * (n / 2);
	else
		std::cout << (a + b) * (n / 2) + a;
}
