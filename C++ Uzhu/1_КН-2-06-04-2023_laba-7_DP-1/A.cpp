#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	if(n == 1)
		std::cout <<  2;
	else if(n == 2)
		std::cout <<  4;
	else {
		std::vector<int> res(n + 1);
		res[1] = 2;
		res[2] = 4;
		for (int i = 3; i <= n; i++)
		{
			res[i] = res[i - 1] + res[i - 2];
		}
		std::cout << res[n];
	}
	
}