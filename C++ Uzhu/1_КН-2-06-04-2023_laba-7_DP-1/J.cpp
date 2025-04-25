#include <bits/stdc++.h>


int main() {
	int n;
	std::cin >> n;
	std::vector<int> y(n + 1);
	std::vector<int> e(n + 1);
	std::vector<int> p(n + 1);
	std::vector<int> res(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> y[i];
	}
	
	e[1] = 0;
	e[2] = std::abs(y[2] - y[1]);
	p[1] = -1;
	p[2] = 1;

	for (int i = 3; i <= n; i++) {
		int a = e[i - 1] + std::abs(y[i] - y[i - 1]);
		int b = e[i - 2] + 3 * std::abs(y[i] - y[i - 2]);
		if (a < b) {
			e[i] = a;
			p[i] = i - 1;
		} else {
			e[i] = b;
			p[i] = i - 2;
		}
	}

	int ptr = 0;
	for (int i = n; i > 0; i = p[i]) {
		res[ptr++] = i;
	}
	
	std::cout << e[n] << '\n' << ptr << '\n';
	for (int i = ptr - 1; i >= 0; i--) {
		std::cout << res[i] << ' ';
	}
	std::cout << '\n';
}
