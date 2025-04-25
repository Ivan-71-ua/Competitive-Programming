#include <bits/stdc++.h>
#define int long long

bool mins(std::vector<int> &nums) {}


int32_t main() {
	int s;
	std::cin >> s;
	std::string res1, res2, res3;
	std::vector<int> nums(9);
	for (int i = 0; i < 9; i++)
	{
		std::cin >> nums[i];
	}
	int prise = 9;
	while(s != 0 && prise > 0) {
		if(s >= nums[prise - 1]) {
			res1 += '0' + prise;
			s -= nums[prise - 1];
		} else {
			prise--;
		}
	}

	prise = 0;
	while(s != 0 && prise < 9) {
		if(s >= nums[prise + 1]) {
			res2 += '0' + prise;
			s -= nums[prise + 1];
		} else {
			prise++;
		}
	}
	/**/
	prise = s;
	while(s != 0 && prise < 9) {
		if(s >= nums[prise + 1]) {
			res2 += '0' + prise;
			s -= nums[prise + 1];
		} else {
			prise++;
		}
	}
	if(res1.size() > res2.size()) {
		std::cout << res1 << '\n';
	} else if (res1.size() < res2.size()) {
		std::cout << res2 << '\n';
	} else {
		std::cout << std::max(res1, res2);
	}

}