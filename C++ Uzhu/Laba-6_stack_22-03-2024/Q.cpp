#include <bits/stdc++.h>

int main() {
	int n;
	std::unordered_map<int, int> quant;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		std::cin >> k;
		quant[k]++;
	}
	int res = -1;
	for (auto now: quant)
	{
		if(now.second > n / 2) {
			res = now.first;
		}
	}
	std::cout << res;
}