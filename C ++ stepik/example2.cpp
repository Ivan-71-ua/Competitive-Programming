
#include <bits/stdc++.h>


int main() {
	int n;
	std::cin >> n;
	std::deque<int> unwashed;
	std::deque<int> cleaned;
	std::vector<int> result;
	for (int i = 1; i <= n; i++) {
		unwashed.push_back(i);
	}
	int c, d;
	while (std::cin >> c >> d) {
		if (c == 1) {
			for (int i = 0; i < d; i++) {
				int plate = unwashed.front();
				unwashed.pop_front();
				cleaned.push_back(plate);
			}
		} else if (c == 2) {
			for (int i = 0; i < d; i++) {
				int plate = cleaned.back();
				cleaned.pop_back();
				result.push_back(plate);
			}
		}
	}
	for (int i = result.size() - 1; i > -1; i--) {
		std::cout << result[i] << std::endl;
	}
}
