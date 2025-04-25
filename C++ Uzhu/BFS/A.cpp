#include <bits/stdc++.h>
#define int long long

int n;
std::pair<int, int> start, finish;
std::queue<std::pair<int, int>> way;

void BFS(std::vector<std::vector<char>> &ans, std::vector<std::vector<int>> &count_step, std::vector<std::vector<bool>> &visited) {
	count_step[way.front().first][way.front().second] = 1;
	while(!way.empty()) {
		int x, y;
		std::tie(x, y) = way.front();
		way.pop();
		if(!visited[x][y]) {
			if(x + 1 < n && !visited[x +1][y] && (ans[x +1][y] == '.' || ans[x +1][y] == 'X')) {
                count_step[x + 1][y] = count_step[x][y] + 1;
                way.push({x + 1, y});
			}
			if(y + 1 < n && !visited[x][y + 1] && (ans[x][y + 1] == '.' || ans[x][y  + 1] == 'X')) {
				count_step[x][y + 1] = count_step[x][y] + 1;
				way.push({x, y + 1});
			}
			if(x - 1 > -1 && !visited[x - 1][y] && (ans[x - 1][y] == '.' || ans[x - 1][y] == 'X')) {
				count_step[x - 1][y] = count_step[x][y] + 1;
				way.push({x - 1, y});
			}
			if(y - 1 > -1 && !visited[x][y - 1] && (ans[x][y - 1] == '.' || ans[x][y - 1] == 'X')) {
				count_step[x][y - 1] = count_step[x][y] + 1;
				way.push({x, y -1});
			}
			visited[x][y] = true;
		}
	}
}

int32_t main() {
	std::cin >> n;
	std::vector<std::vector<int>> count_step(n, std::vector<int>(n, -1));
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
	std::vector<std::vector<char>> ans(n, std::vector<char>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> ans[i][j];
			if(ans[i][j] == '@') {
				start = {i, j};
			}
			if(ans[i][j] == 'X') {
				finish = {i, j};
			}
		}
	}
	way.push(start);
	BFS(ans, count_step, visited);
	if(count_step[finish.first][finish.second] == -1) {
		std::cout << "N\n";
	} else {
		std::cout << "Y\n";
		int xf, yf;
		std::tie(xf, yf) = finish;
		//ans[xf][yf] = '+';
		while(count_step[xf][yf] != 1) {
			if(xf + 1 < n && count_step[xf +1][yf] == count_step[xf][yf] - 1) {
				ans[xf][yf] = '+';
				xf++;
			}
			else if(xf - 1 > -1 && count_step[xf - 1][yf] == count_step[xf][yf] - 1) {
				ans[xf][yf] = '+';
				xf--;
			}
			else if(yf + 1 < n && count_step[xf][yf + 1] == count_step[xf][yf] - 1) {
				ans[xf][yf] = '+';
				yf++;
			}
			else if(yf - 1 > -1 && count_step[xf][yf - 1] == count_step[xf][yf] - 1) {
				ans[xf][yf] = '+';
				yf--;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << ans[i][j];
			}
			std::cout << '\n';
		}
	}
}