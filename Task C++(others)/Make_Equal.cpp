#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	fast;
	int t;
	std::cin >> t;
	for (int i = 0; i  < t; t++)
	{
		int n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> arr[i];
		}
		int k = (n +1) / 2;
		int tp = 0;
		for (int i = 0; i < n; i++)
		{
			if(arr[i] < k) {
				int o = tp + arr[i];
				if(o >= k) {
					tp = o - k;
				} else {
					std::cout << "NO\n";
					break;
				}
			} else {
				tp += arr[i] - k;
			}
		}
		if(tp == 0)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
	
}