#include <bits/stdc++.h>
#define int long long


int32_t main() {
	int n;
	std::cin >> n;
	if(n == 1 || n == 0)
		std::cout <<  1;
	else if(n == 2)
		std::cout <<  2;
	else if(n == 3)
		std::cout <<  4;
	else {
		std::vector<int> res(n + 1);
		res[1] = 1;
		res[2] = 2;
		res[3] = 4;
		for (int i = 4; i <= n; i++)
		{
			res[i] = res[i - 1] + res[i - 2] + res[i -3];
		}
		std::cout << res[n];
	}
}