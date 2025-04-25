#include <bits/stdc++.h>


void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	int k = 0;
	for (int i = 0; i < n - 1; i++) {
		long long a = arr[i], b = arr[i + 1];
		if(a < b)
			std::swap(a, b);
		if(a < b * 2) {
			std::cout << "YES\n";
			return;
		}
	}
	std::cout << "NO\n";
}


int main() {
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}