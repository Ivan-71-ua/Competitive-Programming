#include <bits/stdc++.h>

int main() {
	std::vector<int> res(7);
	int a, b, c;
	for (int i = 0; i < 7; i++)
	{
		std::cin >> res[i];
	}
	std::stable_sort(res.begin(), res.end());
	a = res[0];
	int tmp = res.back() - a;
	for (int i = 1; i < 6; i++)
	{
		int k = res[i];
		for (int j = i + 1; j < 6; j++)
		{
			if(k + res[j] == tmp) {
				b = k;
				c = res[j];
				break;
			}
		}
		
	}
	std::cout << a << ' ' << b << ' ' << c;
}