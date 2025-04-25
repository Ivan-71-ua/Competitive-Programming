#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	fast;
	std::vector<int> ans(10);
	std::string ss;
	std::cin >> ss;
	char k = '0';
	for (int i = 0; i < 10; i++)
	{
		ans[i] = std::count(ss.begin(), ss.end(), k);
		k++;
	}
	for (auto now: ans)
	{
		std::cout << now << ' ';
	}
	
}