#include <bits/stdc++.h>


int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int n, k;
		std::cin >> n >> k;
		long long sum = 0, mul = n + 1, cur = 1;
		while(n >= k) {
			if(n & 1) sum += cur;
			n >>= 1;
			cur <<= 1;
		}
		std::cout << mul * sum / 2 << '\n';
	}
}