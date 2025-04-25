#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	int t;
	std::cin >> t;
	std::vector<int> fr(t);
	for (int i = 0; i < t; i++)
	{
		std::cin >> fr[i];
	}
	int k;
	std::cin >> k;
	std::vector<int> sc(k);
	for (int i = 0; i < k; i++)
	{
		std::cin >> sc[i];
	}
	std::vector<int> ans(t + k);
	int f = 0;
	int l = 0;
	int g = 0;
	for (; f < t && l < k; g++)
	{
		if(fr[f] <= sc[l]) {
			ans[g] = fr[f];
			f++;
		} else {
			ans[g] = sc[k];
			k++;
		}
	}
	while (f < t)
	{
		ans[g] = fr[f];
		g++;
		f++;
	}
	while (l < k)
	{
		ans[g] = sc[l];
		g++;
		l++;
	}
	for (int i = 0; i < t + k; i++)
	{
		std::cout << ans[i] << ' ';
	}
}