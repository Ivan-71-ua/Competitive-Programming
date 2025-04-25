#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	fast;
	int t, q;
	std::cin >> t >> q;
	std::vector<std::vector<int>> cow(t +1, std::vector<int>(3));
	for (int i = 1; i <= t; i++)
	{
		int k;
		std::cin >> k;
		cow[i][k - 1]++;
		cow[i][0] += cow[i - 1][0];
		cow[i][1] += cow[i - 1][1];
		cow[i][2] += cow[i - 1][2];
	}
	for (int i = 0; i < q; i++)
	{
		int l, r;
		std::cin >> l >> r;
		std::cout << cow[r][0] - cow[l - 1][0] << ' ' << cow[r][1] - cow[l - 1][1] << ' ' << cow[r][2] - cow[l - 1][2] << '\n';
	}
}