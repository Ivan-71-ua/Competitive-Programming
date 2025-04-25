#include <bits/stdc++.h>
#define int long long


int32_t main() {
	int n, k;
	std::cin >> n >> k;
	std::string st;
	std::getline(std::cin, st);
	std::getline(std::cin, st);
	std::stringstream strem(st);
	int size = 0;
	while(strem >> st) {
		if(size + st.size() <= k) {
			std::cout << st << ' ';
			size += st.size();
		} else {
			std::cout << '\n';
			std::cout << st << ' ';
			size = st.size();
		}
	}
}
