#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	fast;
	std::multiset<int> ans;
	int k;
	std::cin >> k;
	for (int i = 0; i < k; i++)
	{
		int tp;
		std::cin >> tp;
		ans.insert(tp);
	}
	std::cin >> k;
	for (int i = 0; i < k; i++)
	{
		int tp;
		std::cin >> tp;
		ans.insert(tp);
	}
	std::cin >> k;
	for (int i = 0; i < k; i++)
	{
		int tp;
		std::cin >> tp;
		ans.insert(tp);
	}
	for (auto now: ans)
	{
		std::cout << now << ' ';
	}
	
}