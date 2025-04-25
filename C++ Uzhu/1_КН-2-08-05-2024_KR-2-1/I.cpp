
#include <bits/stdc++.h>

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.second < b.second;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> intervals;
	for (int i = 0; i < n; i++) {
		int start, end;
		std::cin >> start >> end;
		intervals.emplace_back(start, end);
	}
	std::sort(intervals.begin(), intervals.end(), compare);
	int count = 1;
	int current = 0;
	for (int i = 1; i < n; i++) {
		if (intervals[i].first >= intervals[current].second) {
				current = i;
				count++;
		}
	}
	std::cout << count << std::endl;
	return 0;
}
