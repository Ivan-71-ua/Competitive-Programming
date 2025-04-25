

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






int main() {
	int k;
	std::cin >> k;
	int cnt = 1;

	while (k--) {
		int n;
		std::cin >> n;
		std::vector<int> road(n - 1);

		for (int i = 0; i < n - 1; ++i) {
			std::cin >> road[i];
		}

		int cur_sum = 0, max_sum = INT_MIN;
		int start = 0, best_l = -1, best_r = -1, cur_start = 0;

		for (int i = 0; i < n - 1; ++i) {
			cur_sum += road[i];

			if (cur_sum > max_sum || (cur_sum == max_sum && i - cur_start > best_r - best_l)) {
					max_sum = cur_sum;
					best_l = cur_start;
					best_r = i;
			}

			if (cur_sum < 0) {
					cur_sum = 0;
					cur_start = i + 1;
			}
		}

		if (max_sum > 0) {
			std::cout << "The nicest part of route " << cnt << " is between stops " << best_l + 1 << " and " << best_r + 2 << '\n';
		} else {
			std::cout << "Route " << cnt << " has no nice parts\n";
		}

		cnt++;
	}

	return 0;
}
