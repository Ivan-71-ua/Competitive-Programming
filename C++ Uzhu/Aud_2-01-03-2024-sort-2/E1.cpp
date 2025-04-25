#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

std::vector<int> is_there(1000000 + 1, 0);

int32_t main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string tp;
		std::cin >> tp;
		if(tp.size() < 8) {
				int k = std::stoi(tp);
				if(k > -1 && k < 1000000 + 1)
				{
					is_there[k] = 1;
				}
		}
	}
	for (int i = 0; i < 1000000 + 1; i++)
	{
		if(is_there[i] == 0) {
			std::cout << i;
			break;
		}
	}
}