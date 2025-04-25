#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n, q;
	std::string s;
	std::cin >> n >> q;
	std::cin >> s;
	std::vector<char> way(s.begin(), s.end());
	std::vector<int> dancer(n, 1);
	for (int i = 0; i < q; i++)
	{
		char ch, w;
		std::cin >> ch >> w;
		for (int j = 0; j < s.size(); j++)
		{
			if(way[j] = ch) {
				if(w == 'L') {
					if(j - 1 < 0) {
						dancer[j] = 0;
					} else {
						dancer[j - 1] += dancer[j];
						dancer[j] = 0;
					}
				} else {
					if(j + 1 < s.size()) {
						dancer[j + 1] += dancer[j];
						dancer[j] = 0;
					} else {
						dancer[j] = 0;
					}
				}
			}
		}
		int ans = 0;
		for (auto now: dancer)
		{
			ans += now;
		}
		std::cout << ans;
	}
	
}