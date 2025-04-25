#include<bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	while (t--)
	{
		int a, b, c, n;
		std::cin >> a >> b >> c >> n;
		int arr[3]{a, b, c};
		std::sort(arr, arr + 3);
		
		if((arr[2] - arr[1]) + (arr[2] - arr[0]) <= n && ( n -((arr[2] - arr[1]) + (arr[2] - arr[0]))) % 3  == 0) {
			std::cout << "YES\n";
		} else
			std::cout << "NO\n";
	}
	
}