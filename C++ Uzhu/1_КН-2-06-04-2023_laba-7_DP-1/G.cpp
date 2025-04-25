#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> res(n + 2);
	res[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		res[i] = i;
		for (int j = 1; 2 * j < i; j++)
		{
			if(res[j] + res[i -j] < res[i])
				res[i] = res[j] + res[i - j];
		}
		for (int j = 2; j * j < n; j++)
		{
			if(i % j == 0) {
				if(res[j] + res[i / j] < res[i])
					res[i] = res[j] + res[i / j];
			}
		}
	}
	std::cout << res[n];
}