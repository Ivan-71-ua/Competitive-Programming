#include <bits/stdc++.h>

int main() {
	std::string s;
	std::cin >> s;
	int k = s.size() / 4;
	std::string res;
	for (int i = 0; i <= k; i++)
	{
		res += 'A';
	}
	std::cout << res;
}