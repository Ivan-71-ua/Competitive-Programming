#include <bits/stdc++.h>

int main(){
	int n;
	std::cin >> n;
	std::vector<int> degree(n + 1);
	for (int i = 0; i < n -1; i++)
	{
		int a, b;
		std::cin >> a >> b;
		degree[a]++;
		degree[b]++;
	}
	int res = 0;
	for (auto k: degree)
	{
		if(k > 2) {
			res += k - 2;
		}
	}
	std::cout << res;
}