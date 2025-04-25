#include <unordered_map>
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
#include <cstdint>

int max_range(std::vector<int> arr) {
	long long res = arr[0];
	int cur_s = 0;
	for (auto n: arr)
	{
		cur_s += n;
		res = std::max(res, (long long)cur_s);
		if(cur_s < 0)
			cur_s = 0;
	}
	return res;
}


int main() {
	int n;
	while(std::cin >> n && n) {
		int tmp;
		std::vector<int> arr;
		for (int i = 0; i < n; i++) {
			std::cin >> tmp;
			arr.push_back(tmp);
		}
		int k = max_range(arr);
		if(k <= 0)
			std::cout << "Losing streak.\n";
		else {
			std::cout << "The maximum winning streak is " << k << ".\n";
		}
	}
}