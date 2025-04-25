#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	fast;
	int t;
	std::cin >> t;
	while(t--) {
		int k;
		std::cin >> k;
		std::vector<int> ass(k);
		for (int i = 0; i < k; i++)
		{
			std::cin >> ass[i];
		}
		std::sort(ass.begin(), ass.end());
		int res = 0;
		for (int i = 0; i < k; i++)
		{
			if(ass[i] > i +1) {
				res = -1;
				break;
			}
			res += i + 1 - ass[i];
		}
		std::cout << res << '\n';
	}
}