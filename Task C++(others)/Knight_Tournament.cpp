#include <bits/stdc++.h>


int main() {
   int n, m;
   std::cin >> n >> m;
	std::set<int> alive;
	std::vector<int> res(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		alive.insert(i);
	}
	for (int i = 0; i < m; i++)
	{
		int l, r, x;
		std::cin >> l >> r >> x;
		std::vector<int> del;
		auto cur = alive.lower_bound(l);
		while(cur != alive.end()) {
			if(*cur > r) break;
			if(*cur != x) {
				res[*cur] = x;
				del.push_back(*cur);
			}
			cur++;
		}
		for (auto now: del)
		{
			alive.erase(now);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		std::cout << res[i] << ' ';
	}
	

	return 0;
}
