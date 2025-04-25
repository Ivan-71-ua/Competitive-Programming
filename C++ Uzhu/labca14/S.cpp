#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long




int32_t main() {
	int target, n;
	std::cin >> n >> target;
	std::vector<int> numbers(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> numbers[i];
	}
	
	int i = 0;
	int j = numbers.size() - 1;
	bool is = false;
	while (i < j) {
		int sum = numbers[i] + numbers[j];
		if (sum < target) {
			i++;
		} else if (sum > target) {
			j--;
		} else {
			is = true;
			break;
		}
	}
	if(is) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
}