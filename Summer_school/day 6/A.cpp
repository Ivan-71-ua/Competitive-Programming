#include <bits/stdc++.h>


int main() {
	int n;
	std::cin >> n;
	int i = 1;
	int ans = 0;
	while(i <= n) {
		int v = n / i;
		int l = n / v + 1;
		ans += v * (l - i);
		i = l;
	}
	std::cout << ans;
}