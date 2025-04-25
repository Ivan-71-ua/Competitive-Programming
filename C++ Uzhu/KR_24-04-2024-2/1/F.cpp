#include <bits/stdc++.h>
//#define int long long
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int32_t main() {
	fast;
	int n, s;
	std::cin >> n >> s;
	int res = -1;
	for (int i = 0; i < n; i++) {
		int manat, kopecks;
		std::cin >> manat >> kopecks;
		if (manat < s || (manat == s && kopecks == 0)) {
			res = std::max(res, (100 - kopecks)% 100);  
		} 
	}
	std::cout << res << std::endl;  
}
