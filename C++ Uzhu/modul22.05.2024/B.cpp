#include <bits/stdc++.h>

int main() {
	std::string st;
	std::cin >> st;
	int res = 0;
	for (int i = 0; i < st.size(); i++)
	{
		if((st[i] -'0') % 2 != 0)
			res++;
	}
	std::cout << res;
}