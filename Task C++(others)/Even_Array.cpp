#include <bits/stdc++.h>
#define ll long long
#define db double





int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int k;
		std::cin >> k;
		int arr_v[k];
		for (int j = 0; j < k; j++)
		{
			std::cin >> arr_v[j];
		}
		int h = 0, nh = 0;
		for (int l = 0; l < k; l++)
		{
			if(l  % 2 == 0 && arr_v[l] % 2 != 0) {
				h++;
			}
			else if(l  % 2 != 0 && arr_v[l] % 2 == 0) {
				nh++;
			}
		}
		if(nh == h) {
			std::cout << h << "\n";
		}
		else {
			std::cout << -1 << "\n";
		}
		}
	
}