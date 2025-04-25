#include <bits/stdc++.h>
#define int long long



int32_t main() {
	int n;
	std::cin >> n;
	int res = 0;
	while(n != 0) {
		std::string st = std::to_string(n);
		std::stable_sort(st.begin(), st.end(), std::greater());
		n -= (st[0] - '0');
		res++;
	}
	std::cout << res;
}