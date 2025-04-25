#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	std::vector<int> res;
	for (int i = 0; i < 4; i++)
	{
		int tp;
		std::cin >> tp;
		if(tp == 0)
			res.push_back(tp);
		else {
			if(std::find(res.begin(), res.end(), tp) == res.end()) {
				res.push_back(tp);
			}
		}
	}
	std::cout << 4 - res.size();
}