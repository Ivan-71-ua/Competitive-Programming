#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long


int32_t main() {
	std::string ss;
	std::cin >> ss;
	std::set<char> ans;
	for (int i = 0; i < ss.size(); i++)
	{
		ans.insert(ss[i]);
	}
	std::cout << ans.size();
}