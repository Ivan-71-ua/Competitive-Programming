#include <bits/stdc++.h>


int main() {
	int n;
	int prev = -1;
	int res = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		std::cin >> k;
		if(prev == -1) {
			prev = k;
		} else {
			res = std::max(res, k - prev);
			prev = std::min(prev, k);
		}
	}
	std::cout << res;
}