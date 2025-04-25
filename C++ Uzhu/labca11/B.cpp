#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	fast;
	int t;
	std::cin >> t;
	std::vector<int> Hrozhy(t);
	for (int i = 0; i < t; i++)
	{
		std::cin >> Hrozhy[i];
	}
	std::vector<int> ans(t);
	int res = 1;
	for (int i = 0; i < t; i++)
	{
		ans[i] = res;
		res *= Hrozhy[i];
	}
	res = 1;
	for (int i = t - 1; i >= 0; i--)
	{
		ans[i] *= res;
		res *= Hrozhy[i];
	}
	for (int i = 0; i < t; i++)
	{
		std::cout << ans[i] << ' ';
	}
}