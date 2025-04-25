#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int k;
		std::cin >> k;
		std::string ss;
		std::cin >> ss;
		int r, l;
		for (int i = 0; i < k; i++)
		{
			if(ss[i] == 'B') {
				r = i;
				break;
			}
		}
		for (int i = k -1; i >= 0; i--)
		{
			if(ss[i] == 'B') {
				l = i;
				break;
			}
		}
		std::cout << l - (r - 1) << '\n';
	}
}