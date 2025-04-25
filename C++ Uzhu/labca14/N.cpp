#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	int t;
	std::cin >> t;
	std::vector<int> res(t);
	for (int i = 0; i < t; i++)
	{
		std::cin >> res[i];
	}
	int i = 0;
	int j = t - 1;
	for (; i <= j; )
	{
		std::cout << res[i++] << ' ';
		if(i > j) break;
		std::cout << res[j--] << ' ';
	}
	
}