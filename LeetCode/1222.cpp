#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::vector<int>> queensAttacktheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king) {
		std::set<std::pair<int, int>> set_of_queen;
		for (auto q: queens)
		{
			set_of_queen.insert({q[0], q[1]});
		}
		int x = king[0], y = king[1];
		std::vector<std::vector<int>> ans;
		for (int x_r = x + 1; x_r < 8; x_r++)
		{
			if(set_of_queen.count({x_r, y})) {
				ans.push_back({x_r, y});
				break;
			}
		}
		for (int x_l = x - 1; x_l > -1; x_l--)
		{
			if(set_of_queen.count({x_l, y})) {
				ans.push_back({x_l, y});
				break;
			}
		}
		for (int y_u = y + 1; y_u < 8; y_u++)
		{
			if(set_of_queen.count({x, y_u})) {
				ans.push_back({x, y_u});
				break;
			}
		}
		for (int y_d = y - 1; y_d > - 1; y_d--)
		{
			if(set_of_queen.count({x, y_d})) {
				ans.push_back({x, y_d});
				break;
			}
		}
		for (int xs = x + 1, ys = y + 1; xs < 8 && ys < 8; xs++, ys++)
		{
			if(set_of_queen.count({xs, ys})) {
				ans.push_back({xs, ys});
				break;
			}
		}
		for (int xn = x - 1, yn = y - 1; xn > -1 && yn > -1; xn--, yn--)
		{
			if(set_of_queen.count({xn, yn})) {
				ans.push_back({xn, yn});
				break;
			}
		}
		for (int xs = x - 1, ys = y + 1; xs > -1 && ys < 8; xs--, ys++)
		{
			if(set_of_queen.count({xs, ys})) {
				ans.push_back({xs, ys});
				break;
			}
		}
		for (int xs = x + 1, ys = y - 1; xs < 8 && ys > -1; xs++, ys--)
		{
			if(set_of_queen.count({xs, ys})) {
				ans.push_back({xs, ys});
				break;
			}
		}
		return ans;
	}
};

int main() {
	std::vector<std::vector<int>> ss{{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4}};
	std::vector<int> k{0, 0};
	Solution ans;
	ans.queensAttacktheKing(ss, k);
}