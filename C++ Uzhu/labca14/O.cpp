#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	std::string ss;
	std::cin >> ss;
	int res = ss.size();
	int i = 0;
	int j = ss.size() - 1;
	while(i < j && ss[i] != ss[j]) {
		i++;
		j--;
		res -= 2;
	}
	std::cout << res;
}