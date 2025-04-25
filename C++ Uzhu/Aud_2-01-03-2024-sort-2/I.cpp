#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	std::multiset<int> tp;
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int k;
		std::cin >> k;
		tp.insert(k);
	}
	int p;
	std::cin >> p;
	for (int i = 0; i < p; i++)
	{
		int k;
		std::cin >> k;
		tp.insert(k);
	}
	for (auto now: tp)
	{
		std::cout << now << ' ';
	}
	
}