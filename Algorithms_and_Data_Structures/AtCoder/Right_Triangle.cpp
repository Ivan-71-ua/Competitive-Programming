#include <bits/stdc++.h>

int main() {
	int a_x, a_y, b_x, b_y, c_x, c_y;
	std::cin >> a_x >> a_y >> b_x >> b_y >> c_x >> c_y;
	int ab2 = (a_x - b_x) * (a_x - b_x) + (a_y - b_y) * (a_y - b_y);
	int bc2 = (b_x - c_x) * (b_x - c_x) + (b_y - c_y) * (b_y - c_y);
	int ca2 = (c_x - a_x) * (c_x - a_x) + (c_y - a_y) * (c_y - a_y);
	std::vector<int> sides{ab2, bc2, ca2};
	std::sort(sides.begin(), sides.end());
	if (sides[0] + sides[1] == sides[2]) {
		std::cout << "Yes";
	} else {
		std::cout << "No";
	}
}