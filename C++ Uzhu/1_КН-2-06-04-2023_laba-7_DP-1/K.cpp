#include <bits/stdc++.h>


int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 2), b(n +2), c(n + 2), res(n + 2);
	
	for (int i = 1; i <= n; i++)
	{
		std::cin >> a[i] >> b[i] >> c[i];
	}
	res[0] = 0;
	res[1] = a[1];
	res[2] = std::min(a[1] + a[2], b[1]);
	for(int i = 3; i <= n; i++)
		res[i] = std::min({res[i-1] + a[i], res[i-2] + b[i-1], res[i-3] + c[i-2]});
	std::cout << res[n];
}