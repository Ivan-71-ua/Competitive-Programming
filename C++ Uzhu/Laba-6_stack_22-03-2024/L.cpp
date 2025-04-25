#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::stack<int> tmp;
	std::vector<int> res;
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		if (a == 1) {
			int k;
			std::cin >> k;
			tmp.push(k);
		} else {
			res.push_back(tmp.top());
			tmp.pop();
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << '\n';
	}
	
}