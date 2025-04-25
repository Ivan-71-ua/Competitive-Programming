#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	std::stack <std::pair<int,int> >bals;
	int n;
	std::cin >> n;
	int sz = 0;
	for (int i = 0; i < n; i++)
	{
		int k;
		std::cin >> k;
		if(bals.empty()) {
			bals.push({k, 1});
			sz++;
			std::cout << sz << '\n';
		} else {
			if(bals.top().first == k) {
				bals.top().second++;
				sz++;
				if(bals.top().second = bals.top().first) {
					int tp = bals.top().second;
					sz -= bals.top().second;
					bals.pop();
				}
				std::cout << sz << '\n';
			}
			else {
				bals.push({k, 1});
				sz++;
				std::cout << sz << '\n';
			}
		}
	}
}