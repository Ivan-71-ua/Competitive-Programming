#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	fast;
	int n;
	std::cin >> n;
	std::vector<int> tp(n + n);
	for (int i = 0; i < n + n; i++)
	{
		std::cin >> tp[i];
	}
	std::sort(tp.begin(), tp.end());
	int ans = 0;
	for (int i = 0; i < n + n; i+= 2)
	{
		ans += tp[i];
	}
	std::cout << ans;
}