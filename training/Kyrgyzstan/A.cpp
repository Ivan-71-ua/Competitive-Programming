#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	int k;
	std::cin >> k;
	if(k >= n) {
		long long res = 0;
		for (int i = 0; i < n; i++)
		{
			res += arr[i];
		}
		std::cout << res;
		return 0;
	} else {
		int l = 0;
		int r = k;
		long long sum = 0;
		long long res = 0;
		for (int i = 0; i < r; i++)
		{
			sum += arr[i];
		}
		res = std::max(res, sum);
		while(r < n) {
			sum += arr[r];
			sum -= arr[l];
			l++;
			r++;
			res = std::max(res, sum);
		}
		std::cout << res;
		return 0;
	}
}