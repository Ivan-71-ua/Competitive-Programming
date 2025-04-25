
#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	int res = 0;
	int cur = arr[0];
	for (int i = 1; i < n; i++)
	{
		if(cur > arr[i]) {
			res = arr[i] - cur;
		}
		cur = arr[i];
	}
	std::cout << res;
}