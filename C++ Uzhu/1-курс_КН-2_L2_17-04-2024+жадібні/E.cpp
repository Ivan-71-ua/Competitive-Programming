#include <bits/stdc++.h>



int main() {
	int n;
	std::cin >> n;
	std::vector<int> tree(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> tree[i];
	}
	std::stable_sort(tree.begin(), tree.end(), std::greater());
	int res = -1;
	for (int i = 0; i < n; i++)
	{
		res = std::max(res, 2 + i + tree[i]);
	}
	std::cout << res;
}
