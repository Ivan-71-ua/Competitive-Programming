#include <bits/stdc++.h>


int main() {
	int n;
	std::cin >> n;
	std::vector < std::pair < std::pair<int, int>, int >> nums;
	for (int i = 0; i < n; i++)
	{
		int cur;
		std::cin >> cur;
		std::string s = std::to_string(cur);
		std::reverse(s.begin(), s.end());
		int rev = std::stoi(s);
		nums.push_back({{rev, -i}, cur});
	}
	std::stable_sort(nums.begin(), nums.end());
	for (auto now: nums)
	{
		std::cout << now.second << ' ';
	}
	
}