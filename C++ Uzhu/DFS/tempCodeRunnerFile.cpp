#include <bits/stdc++.h>



int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	std::vector<bool> used(n + 1, false);
	int k;
	std::cin >> k;
	std::stack<int> qn;
	qn.push(k);
	while(!qn.empty()) {
		int tmp = qn.top();
		std::cout << tmp << ' ';
		qn.pop();
		if(!used[tmp]) {
			used[tmp] = true;
			for (auto now: v[tmp])
			{
				qn.push(now);
			}
		}
	}
}