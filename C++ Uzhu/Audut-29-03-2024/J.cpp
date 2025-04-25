#include <bits/stdc++.h>


int main() {
	int n;
	std::cin >> n;
	std::vector<int> height(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> height[i];
	}
	int l = 0;
	int r = n-1;
	int lmax = INT_MIN;
	int rmax = INT_MIN;
	int ans = 0;
	while (l < r)
	{
		lmax = std::max(lmax, height[l]);
		rmax = std::max(rmax, height[r]);
		ans += (lmax < rmax) ? lmax - height[l++] : rmax - height[r--];
	}
	std::cout << ans;
}