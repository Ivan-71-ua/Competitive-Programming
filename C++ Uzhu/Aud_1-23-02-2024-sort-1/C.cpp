#include <bits/stdc++.h>


int main () {
	int t;
	std::cin >> t;
	std::vector<int> ans(t);
	for (int i = 0; i < t; i++)
	{
		std::cin >> ans[i];
	}
	std::sort(ans.begin(), ans.end(), std::greater());

	for (int i = 0; i < t; i++)
	{
		std::cout << ans[i] << ' ';
	}
}