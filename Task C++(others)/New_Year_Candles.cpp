#include <bits/stdc++.h>

int main() {
	int a, b;
	std::cin >> a >> b;
	int ans = a;
	while (a >= b)
	{
		ans += a / b;
		a = (a / b) + (a % b);
	}
	std::cout << ans;
}