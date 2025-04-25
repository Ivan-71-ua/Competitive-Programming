#include <bits/stdc++.h>

int main() {
	std::map<int, int> price_qual;
	int n;
	std::cin >> n;
	while (n--)
	{
		int a, b;
		std::cin >> a >> b;
		price_qual[a] = b;
	}
	bool ans = false;
	for (auto it = price_qual.begin(); it != price_qual.end(); it++)
	{
		if(it->first != it -> second) {
			ans = true;
			break;
		}
	}
	if (ans) {
		std::cout << "Happy Alex";
	} else {
		std::cout << "Poor Alex";
	}
}