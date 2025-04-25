#include <bits/stdc++.h>
#define ll long long
#define db double





int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int arr_v[3]{};
		for (int j = 0; j < 3; j++)
		{
			std::cin >> arr_v[j];
		}
		std::sort(arr_v, arr_v + 3);
		std::cout << arr_v[1] << "\n";
	}
	
}