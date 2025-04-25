#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int t;
	std::cin >> t;
	while(t--) {
		int k;
		std::cin >> k;
		std::string s;
		std::cin >> s;
		int zero = std::count(s.begin(), s.end(), '0');
		int ones = s.size() - zero;
		if(zero == ones)
			std::cout << zero << '\n';
		else if(zero > ones) {
			std::cout << ones << '\n';
		} else {
			std::cout << zero + 1 << '\n';
		}
	}
}