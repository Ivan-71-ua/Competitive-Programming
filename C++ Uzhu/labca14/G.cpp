#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


bool comp(std::pair<int, std::string> a, std::pair<int, std::string> b) {
	return a.first < b.first;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, std::string>> res(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		std::cin >> a >> b;
		res[i] = std::make_pair(a, b);
	}
	std::stable_sort(res.begin(), res.end(), comp);
	for (int i = 0; i < n; i++)
	{
		std::cout << res[i].first  << ' ' <<  res[i].second << '\n';
	}
	std::cout << '\n';
}