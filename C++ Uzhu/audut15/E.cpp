#include <bits/stdc++.h>

int main() {
	int k, n;
	std::cin >> k;
	std::map<int, int> arr;
	for (int i = 0; i < k; i++)
	{
		int tmp;
		std::cin >> tmp;
		arr[tmp]++;
	}
	for (int i = 0; i < n; i++)
	{
		int ask;
		std::cin >> ask;
		if(arr.count(ask)) {
			std::cout << arr[k] << '\n';
		} else {
			std::cout << 0 << '\n';
		}
	}
	
}