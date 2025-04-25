#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	fast;
	int t;
	std::cin >> t;
	std::vector <int>tp(t);
	for (int i = 0; i < t; i++)
	{
		std::cin >> tp[i];
	}
	std::sort(tp.begin(), tp.end());
	int res = 0;
	for (int i = 1; i < t; i+=2)
	{
		res += tp[i] - tp[i - 1];
	}
	std::cout << res;
}