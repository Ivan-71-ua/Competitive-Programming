#include <bits/stdc++.h>


int main () {
	int t;
	std::cin >> t;
	int arr[t];
	for (int i = 0; i < t; i++)
	{
		std::cin >> arr[i];
	}
	std::sort(arr, arr + t);
	for (int i = 0; i < t; i += 2)
	{
		std::cout << arr[i] << ' ';
	}
	if(t % 2 ==0)
		t++;
	for (int i = t - 2; i  >= 0; i -= 2)
	{
		std::cout << arr[i] << ' ';
	}
}