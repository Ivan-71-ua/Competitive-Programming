#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main ()  {
	int n, m;
	std::cin >> n >> m;
	std::set<int> parked;
	for (int i = 1; i <= n; i++)
	{
		parked.insert(i);
	}
	
	for (int i = 0; i < m; i++)
	{
		char ask;
		int plase;
		std::cin >> ask >> plase;
		if(ask == '+') {
			if(parked.lower_bound(plase) != parked.end()) {
				int tp = *parked.lower_bound(plase);
				parked.erase(tp);
				std::cout << plase << '\n';
			} else {
				int tmin = *std::min_element(parked.begin(), parked.end());
				if(tmin > plase)
					std::cout << -1 << '\n';
				else {
					parked.erase(tmin);
					std::cout << tmin << '\n';
				}
			}
		} else {
			if(parked.count(plase) == 0) {
				std::cout << -2 << '/n';
			} else {
				std::cout << 0 << '/n';
				parked.erase(plase);
			}
		}
	}
}