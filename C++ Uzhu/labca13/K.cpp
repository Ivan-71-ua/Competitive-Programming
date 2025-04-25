#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	fast;
	int n;
	std::cin >> n;
	std::vector<int> tp(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> tp[i];
	}
	std::sort(tp.begin(), tp.end());
	int ans = 0;
	int k = 1;
	for (int i = 0; i < n; i++)
	{
		if(tp[i] >= k) {
			ans++;
			k++;
		}
	}
	std::cout << ans;
}