#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	fast
	int n;
	std::cin >> n;
	std::vector<std::string> str(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> str[i];
	}
	int leght = str[0].size();
	int ans = INT32_MAX;
	for(int i = 0; i < n; i++) {
		int res = 0;
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			int pos = -1;
			for(int k = 0; k < leght; k++) {
				if(str[j].substr(k) + str[j].substr(0, k) == str[i]) {
					pos = k;
					break;
				}
			}
			if(pos == -1) {
				std::cout << -1 << "\n";
				return 0;
			}
			res += pos;
		}
		ans = std::min(ans, res);
	}
	std::cout << ans << "\n";
	return 0;
}
