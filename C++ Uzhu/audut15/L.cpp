#include <bits/stdc++.h>

const long long MAX = 1000000000000000000LL;

void preprocess(std::vector<long long>& v) {
	long long x = 1, y = 1;
	while (x < MAX) {
		while (x * y < MAX) {
				v.push_back(x * y);
				y *= 3;
		}
		x *= 2;
		y = 1;
	}
	std::sort(v.begin(), v.end());
}

int main() {
	std::vector<long long> v;
	preprocess(v);
	long long a, b;
	while (std::cin >> a >> b) {
		int res = std::upper_bound(v.begin(), v.end(), b) - std::upper_bound(v.begin(), v.end(), a - 1);
		std::cout << res << std::endl;
	}
}
