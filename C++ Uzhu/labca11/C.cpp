#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	fast;
	int k;
	std::cin >> k;
	for (int j = 0; j < k; j++)
	{
		int t, m;
		std::cin >> t >> m;
		std::vector<long long> pref_sum(t + 1);
		pref_sum[0] = 0;
		for (int i = 1; i <= t; i++)
		{
			int tp;
			std::cin >> tp;
			pref_sum[i] = pref_sum[i - 1] + tp;
		}
		for (int i = 0; i < m; i++)
		{
			int r, l;
			std::cin >> r >> l;
			std::cout << pref_sum[l] - pref_sum[r - 1] << '\n';
		}
		std::cout << '\n';
	}
}