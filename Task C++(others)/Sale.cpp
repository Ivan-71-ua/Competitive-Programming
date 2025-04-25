#include <bits/stdc++.h>


void HROZNY(){
	int k, h, sum = 0;
	std::cin >> k >> h;
	int arr_v[k];
	for (int i = 0; i < k; i++)
	{
		std::cin >> arr_v[i];
	}
	std::sort(arr_v, arr_v + k);
	for (int i = 0; i < h; i++)
	{
		if(arr_v[i] < 0) {
			sum += abs(arr_v[i]);
		}
		else {
			sum -= arr_v[i];
		}
	}
	std::cout << sum;
}

int main() {
	HROZNY();
}