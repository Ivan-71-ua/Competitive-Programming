#include <bits/stdc++.h>


int main () {
	std::vector<int> arr;
	int tp;
	while(std::cin >> tp) {
		arr.push_back(tp);
	}
	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ' ';
	}
}