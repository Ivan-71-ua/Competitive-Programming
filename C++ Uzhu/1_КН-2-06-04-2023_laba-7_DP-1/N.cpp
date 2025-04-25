#include <bits/stdc++.h>
#define int long long

int32_t main() {
	std::vector<int> tmp(1000000 + 2);
	tmp[1] = 0;
	for (int i = 2; i < 1000000 + 2; i++)
	{
		tmp[i] = tmp[i-1];
		if (i % 2 == 0 && tmp[i/2] < tmp[i]) tmp[i] = tmp[i/2];
		if (i % 3 == 0 && tmp[i/3] < tmp[i]) tmp[i] = tmp[i/3];
		tmp[i]++;
	}
	int n;
	while (std::cin >> n)
	{
		std::cout << tmp[n] << '\n';
	}
}