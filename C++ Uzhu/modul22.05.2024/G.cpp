

#include <bits/stdc++.h>


int main() {
	int n;
	int res = 0;
	std::cin >> n;
	std::vector<int> prise(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> prise[i];
	}
	for (int i = 1; i < n; i++)
	{
		if(prise[i] - prise[i -1] > 0)
			res += prise[i] - prise[i - 1];
	}	
	std::cout << res;
}