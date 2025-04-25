#include <bits/stdc++.h>



void printState(const std::vector<std::vector<int>>& state) {
	for (const auto& line : state) {
		for (auto &col : line)
		{
			std::cout << col;
		}
		std::cout << '\n';
	}
}

void refer(std::vector<std::vector<char>> grid, std::vector<std::vector<int>> &res, int k) {
	int citi1 = 0;
	int n = grid.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if(citi1 == k /2) {
				res[i][j] = 2;
			}
			else {
				if(grid[i][j] == 'C')
					citi1++;
			}
		}
	}
}


int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<char>> grid(n, std::vector<char>(n));
	int cities = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			std::cin >> grid[i][j];
			if(grid[i][j] == 'C')
				cities++;
		}
	}
	std::vector<std::vector<int>> res(n, std::vector<int>(n, 1));
	refer(grid, res, cities);
	printState(res);
	return 0;
}
