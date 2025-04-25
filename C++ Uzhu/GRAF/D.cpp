#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	fast;
	int n, m;
	std::cin >> n >> m;
	std::map<int, std::set<int>> quat_v;
	for (int i = 0; i < m; i++)
	{
		int k, l;
		std::cin >> k >> l;
		quat_v[k].insert(l);
		quat_v[l].insert(k);
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << quat_v[i + 1].size() << " ";
	}
	
}