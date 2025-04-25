#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n;
	std::cin >> n;
	if(n == 0) {
		std::cout << 0;
	} else {
		int ans = INT64_MAX;
		//std::vector<int> dp[(int)cbrt(n)][(int)cbrt(n)];
		for (int i = 0; i <= cbrt(n); i++)
		{
			for (int j = 0; j <= cbrt(n); j++)
			{
				if((i + j) * (i * i + j * j) >= n && (i + j) * (i * i + j * j) < ans) {
					ans = (i + j) * (i * i + j * j);
				}
			}
		}
		std::cout << ans;
	}
}