#include <bits/stdc++.h>
#define int long long

std::string mins(std::string s1, std::string s2) {
	if(s1.size() > s2.size()) {
		return s1;
	} else if(s1.size() < s2.size()) {
		return s2;
	} else {
		return std::max(s1, s2);
	}
}


int32_t main() {
	int s;
	std::cin >> s;
	std::string res1, res2, res3;
	std::string ans;
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
	ans = res1;
	prise = 0;
	while(s != 0 && prise < 9) {
		if(s >= nums[prise + 1]) {
			res2 += '0' + prise;
			s -= nums[prise + 1];
		} else {
			prise++;
		}
	}
	prise = s;
	ans = mins(ans, res2);
	/**/
	int k = std::min_element(nums.begin(), nums.end()) - nums.begin();
	int ost = s % nums[k];
	for (int i = 0; i < s / nums[k]; i++)
	{
		res3 = '0' + k;
	}
	ans = mins(ans, res3);
	std::cout << ans;
}