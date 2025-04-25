#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	std::map<char, int> leter_quatl;
	std::string ss;
	while(std::getline(std::cin, ss)) {
		std::transform(ss.begin(), ss.end(), ss.begin(), tolower);
		char tp = 'a';
		for (int i = 0; i < 26; i++)
		{
			int q = std::count(ss.begin(), ss.end(), tp);
			leter_quatl[tp] += q;
			tp++;
		}
	}
	for (auto now: leter_quatl)
	{
		std::cout << now.second << ' ';
	}
}