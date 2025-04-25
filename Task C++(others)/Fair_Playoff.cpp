#include <bits/stdc++.h>
#define ll long long

int main() {
	ll t;
	std::cin >> t;
	while(t--) {
		int arr_v[4];
		for (int i = 0; i < 4; i++)
		{
			std::cin >> arr_v[i];
		}
		ll max = -1, max_1 = -2, k1 = -1, k2 = -1;
		for (int i = 0; i < 4; i++)
		{
			if(arr_v[i] > max) {
				max_1 = max;
				k2 = k1;
				max = arr_v[i];
				k1 = i;
			}
            else if(arr_v[i] > max_1) {
                max_1 = arr_v[i];
                k2 = i;
            }

		}
		if(k2 <= 1 && k1 >= 2 || k1 <= 1 && k2 >= 2) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}

	}
}