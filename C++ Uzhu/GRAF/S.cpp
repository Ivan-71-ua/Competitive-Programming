#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	int n, m;
	std::cin >> n;
	std::vector<std::vector<int>> matrx(n +1);
	for (int i = 0; i <= n; i++)
	{
		std::string s;
		std::getline(std::cin, s);
		std::stringstream tp(s);
		int k;
		while(tp >> k) {
			matrx[k].push_back(i);
		}
	}
	std::cout << n << '\n';
	for (int i = 1; i <= n; i++)
	{    
		for (int now: matrx[i])
		{
			std::cout << now << ' ';
		}
		std::cout << '\n';
	}

}