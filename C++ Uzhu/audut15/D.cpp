#include <bits/stdc++.h>

int main() {
	int k;
	std::cin >> k;
	std::vector<int> arr(k);
	for (int i = 0; i < k; i++)
	{
		std::cin >> arr[i];
	}
	std::stable_sort(arr.begin(), arr.end());
	std::cout << arr.back();
}