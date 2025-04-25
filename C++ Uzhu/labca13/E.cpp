#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	fast;
	int t;
	std::cin >> t;
	std::vector<int> cor(t);
	std::vector<int> nor(t);
	for (int i = 0; i < t; i++)
	{
		std::cin >> cor[i];
	}
	for (int i = 0; i < t; i++)
	{
		std::cin >> nor[i];
	}
	std::sort(cor.begin(), cor.end());
	std::sort(nor.begin(), nor.end());
	int res = 0;
	for (int i = 0; i < t; i++)
	{
		res = std::max(res, abs(nor[i] - cor[i]));
	}
	std::cout << res;
}