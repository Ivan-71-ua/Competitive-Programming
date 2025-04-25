#include <bits/stdc++.h>
#define int long long

int func(int a, int b) {
	return (a + b) * (a * a + b * b);
}

int32_t main() {
	int n;
	std::cin >> n;
	if(n == 0) {
		std::cout << 0;
	} else {
		int ans = INT64_MAX;
		int b = 1000000 + 3;
		for (int i = 0; i < b; i++)
		{
			while(func(i, b) >= n && b > 0) {
				ans = std::min(ans, func(i, b));
				b--;
			}
		}
		std::cout << ans;
	}
}