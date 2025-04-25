#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> dig(n + 1);
	std::vector<int> biger(n + 1);
	std::vector<int> res(n + 1);
	for (int i = 1; i < n + 1; i++)
	{
		std::cin >> dig[i];
	}
	std::stack<int> way;
	way.push(1);
	for (int i = 2; i < n + 1; i++)
	{
		while(!way.empty()) {
			int j = way.top();
			if (dig[j] >= dig[i])
				break;
			biger[j] = i;
			way.pop();
		}
		way.push(i);
	}
	res[n] = 0;
	for (int i = n  - 1; i >= 1; i--)
	{
		if(biger[i] == 0)
			res[i] = 0;
		else {
			res[i] = res[biger[i]] + 1;
		}
	}
	for (int i = 1; i < n + 1;i++)
	{
		std::cout << res[i] << ' ';
	}
}