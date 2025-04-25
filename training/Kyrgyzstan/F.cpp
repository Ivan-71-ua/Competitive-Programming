#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <climits>
#include <string>

int main() {
	int n;
	std::cin >> n;
	std::map<int, int> count;
	for (int i = 0; i < n; i++)
	{
		int tmp; 
		std::cin >> tmp;
		count[tmp]++;
	}
	int ans = 0;
	int coutn = n + 3;
	for (auto& now : count)
	{
		if (coutn > now.second) {
			ans = now.first;
			coutn = now.second;
		}
	}
	std::cout << ans;
}