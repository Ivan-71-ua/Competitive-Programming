#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int s;
	std::cin >> s;
	std::string res;
	std::vector<int> nums(9);
	for (int i = 0; i < 10; i++)
	{
		std::cin >> nums[i];
	}
	int prise = 9;
	while(s != 0 && prise > 0) {
		if(s >= nums[prise - 1]) {
			res += '0' + prise;
			s -= nums[prise];
		} else {
			prise--;
		}
	}
	std::cout << res;
}