
#include <bits/stdc++.h>



class Solution {
public:
	bool checkValidCuts(int n, std::vector<std::vector<int>>& rectangles) {
		std::vector<std::pair<int, int>> pair_ax, pair_ay;
		for (int i = 0; i < rectangles.size(); i++) {
			int x1 = rectangles[i][0], x2 = rectangles[i][2], y1 = rectangles[i][1], y2 = rectangles[i][3];
			pair_ax.push_back({x1, x2});
			pair_ay.push_back({y1, y2});
		}
		std::sort(pair_ax.begin(), pair_ax.end());
		std::vector<int> ax{-1};
		for (int i = 0; i < pair_ax.size(); i++) {
			if(pair_ax[i].first >= ax.back()) {
				ax.push_back(pair_ax[i].second);
			} else {
				ax.back() = std::max(ax.back(), pair_ax[i].second);
			}
			if(ax.size() > 3) {
				return true;
			}
		}
		std::sort(pair_ay.begin(), pair_ay.end());
		ax.assign(1, -1);
		for (int i = 0; i < pair_ay.size(); i++) {
			if(pair_ay[i].first >= ax.back()) {
				ax.push_back(pair_ay[i].second);
			} else {
				ax.back() = std::max(ax.back(), pair_ay[i].second);
			}
			if(ax.size() > 3) {
				return true;
			}
		}
		return false;
	}
};


int main() {
	std::vector<std::vector<int>> aa{{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
	std::stable_sort(aa.begin(), aa.end());
	for (auto &v: aa) {
		for (auto &e: v) {
			std::cout << e << ' ';
		}
		std::cout << '\n';
	}
}