#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b, k;
		std::cin >> a >> b >> k;
		std::set<int> arr1;
		std::set<int> arr2;
		for (int i = 0; i < a; i++)
		{
			int tp;
			std::cin >> tp;
			if(tp <= k) {
				arr1.insert(tp);
			}
		}
		for (int i = 0; i < b; i++)
		{
			int tp;
			std::cin >> tp;
			if(tp <= k) {
				arr2.insert(tp);
			}
		}
		if(std::min(arr1.size(), arr2.size()) < k / 2)
			std::cout << "NO\n";
		else {
			for (auto now:arr2)
			{
				arr1.insert(now);
			}
			if(arr1.size() == k)
				std::cout << "YES\n";
			else {
				std::cout << "NO\n";
			}
		}
	}
}