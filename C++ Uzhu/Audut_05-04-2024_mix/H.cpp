#include <bits/stdc++.h>

int main() {
	int a, b;
	std::cin >> a >> b;
	int d = std::gcd(a, b);
	std::vector<int> v;
	for (int i = 1; i * i <= d; i++) {
		if (d % i == 0) {
				v.push_back(i);
				if (i != d / i) { 
					v.push_back(d / i);
				}
		}
	}
	int n; 
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int low, high;
		std::cin >> low >> high;
		int res = -1;
		for (int div : v) {
				if (div >= low && div <= high) {
					res = std::max(res, div);
				}
		}
		std::cout << res << std::endl;
	}
}
