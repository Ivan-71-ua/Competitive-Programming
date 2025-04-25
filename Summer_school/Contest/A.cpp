#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> round(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> round[i];
	}
	std::unordered_map<int, int> prev;
	std::vector<int> toys(m + 1);
	for (int i = 0; i < n; i++)
	{
		toys[round[i]] += i * prev[round[i]];
		prev[round[i]]++;
	}
	std::cout << *std::max_element(toys.begin(), toys.end());
}