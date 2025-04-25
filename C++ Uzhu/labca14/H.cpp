#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	fast;
	int n;
	std::cin >> n;
	std::vector<int> res(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> res[i];
	}
	std::vector<std::pair<int, int>> ans;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		while(res[i] != i) {
			ans.push_back(std::make_pair(res[i], i));
			std::swap(res[i], res[res[i]]);
			k++;
		}
	}
	std::cout << k << '\n';
	for (int i = 0; i < k; i++)
	{
		std::cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
}