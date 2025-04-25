#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n;
	std::cin >> n;
	std::vector<int> k1;
	std::vector<int> k2;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = n; i > 0; i--)
	{
		if(sum1 < sum2) {
			sum1 += i;
			k1.push_back(i);
		} else {
			sum2 += i;
			k2.push_back(i);
		}
	}
	std::cout << k1.size() << ' ' << k2.size() << '\n';
	for (auto now : k1)
	{
		std::cout << now << ' ';
	}
	std::cout << '\n';
	for (auto now : k2)
	{
		std::cout << now << ' ';
	}
}