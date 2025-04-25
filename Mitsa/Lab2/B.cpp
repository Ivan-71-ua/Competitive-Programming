#include <bits/stdc++.h>

void dfs(int x, int y, int &square, std::vector<std::vector<char>> list, int n) {
	if(x < 0 || y < 0 || x >= n || y >= n || list[x][y] == '*')
		return;
	square++;
	list[x][y] = '*';
	dfs(x + 1, y, square, list, n);
	dfs(x - 1, y, square, list, n);
	dfs(x, y + 1, square, list, n);
	dfs(x, y - 1, square, list, n);
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<char>> list(n, std::vector<char> (n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char ch;
			std::cin >> ch;
			list[i][j] = ch;
		}
	}
	int x, y;
	std::cin >> x >> y;
	x--;
	y--;
	int res = 0;
	dfs(x, y, res, list, n);
	std::cout << res;
}