#include <bits/stdc++.h>

int main() {
	int k;
	std::cin >> k;
	int n, a, b, c;
	std::cin >> n >> a >> b >> c;
	if(k == 1) {
		if(a + b +c - 2 * n < 0)
			std::cout << 0;
		else {
			std::cout << a + b + c - 2 * n;
		}
	} else {
		std::cout << std::min({a, b, c});
	}
}