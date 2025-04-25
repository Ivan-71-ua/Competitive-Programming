#include <bits/stdc++.h>

int main() {
	int k;
	std::cin >> k;
	std::vector<int> lol(k);
	for (int i = 0; i < k; i++)
	{
		std::cin >> lol[i];
	}
	int tp = -1;
	for (int i = k - 2; i >= 0; i--)
	{
		if(lol[i] > lol[i +1]) {
			tp = i;
			break;
		}
	}
	std::cout << tp + 1;
}