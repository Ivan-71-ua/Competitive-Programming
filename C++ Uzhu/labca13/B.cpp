#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	int k, t;
	std::cin >> k >> t;
	std::vector<int> cast(k);
	std::vector<int> crush(t);
	for (int i = 0; i < k; i++)
	{
		std::cin >> cast[i];
	}
	for (int i = 0; i < t; i++)
	{
		std::cin >> crush[i];
	}
	std::sort(crush.begin(), crush.end());
	std::sort(cast.begin(), cast.end());
	int ans = 0;
	for (int j = 0; ans < k && j < t;  j++)
	{
		if(cast[ans] <= crush[j])
			ans++;
	}
	std::cout << ans;
}