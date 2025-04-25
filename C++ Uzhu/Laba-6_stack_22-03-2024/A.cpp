#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n;
	std::cin >> n;
	std::stack<std::pair<int, int>> heigh;
	int res = 0;
	heigh.push({0, -1});
	for (int i = 1; i <= n +1; i++)
	{
		int h;
		if(i  <= n)
			std::cin >> h;
		else
			h = 0;
		int x = i;
		while(h <= heigh.top().second) {
			x = heigh.top().first;
			int htp = heigh.top().second;
			heigh.pop();
			int squre = htp * (i - x);
			res = std::max(res, squre);
		}
		heigh.push({x, h});
	}
	std::cout << res;
}
