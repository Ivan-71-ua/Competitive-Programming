#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n;
	std::cin >> n;
	int pref = 0;
	int cur = 1;
	if(n == 1) {
		std::cout << 1;
	} else {
		for (int i = 1; i < n; i++)
		{
			int tmp = cur;
			cur = cur + pref;
			pref = tmp;
		}
		std::cout << cur;
	}
}