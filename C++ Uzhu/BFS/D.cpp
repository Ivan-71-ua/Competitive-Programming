#include <bits/stdc++.h>
#define int long long

int n, m;
std::queue<std::pair<std::pair<int, int>,int>> way;

int BFS(std::vector<std::vector<char>> &date, std::vector<std::vector<bool>> &used) {
	//int res = INT32_MAX;
	while(!way.empty()) {
		int x, y, dis;
		x = way.front().first.first;
		y = way.front().first.second;
		dis = way.front().second;
		way.pop();
		
		if(x == n - 1) {
			//res = std::min(res, dis);
			return dis;
		}
				
		if(y + 1 < m && !used[x][y + 1] && date[x][y + 1] == '#') {
				way.push({{x, y + 1}, dis + 1});
				used[x][y +1] = true;
		}
		if(x + 1 < n && !used[x + 1][y] && date[x + 1][y] == '#' ) {
				way.push({{x + 1, y}, dis + 1});
				used[x + 1][y] = true;
		}
		if(x - 1 > -1 && !used[x - 1][y] && date[x - 1][y] == '#') {
				way.push({{x - 1, y}, dis +1});
				used[x - 1][y] = true;
		}
		if(y - 1 > -1 && !used[x][y - 1] && date[x][y - 1] == '#') {
				way.push({{x, y - 1}, dis +1});
				used[x][y - 1] = true;
		}
		
	}
	//return  res;
	return 0;
}



int32_t main() {
	std::cin >> n >> m;
	std::vector<std::vector<char>> date(n, std::vector<char>(m));
	std::vector<std::vector<bool>> used(n, std::vector<bool>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
				std::cin >> date[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
				if(date[i][j - 1] == '#' && date[i][j] == '.') {
					date[i][j] = '#';
					break;
				}
		}
	}
	for (int i = 0; i < m; i++)
	{
		if(date[0][i] == '#') {
				way.push({{0, i}, 1});
				used[0][i] = true;
		}
	}
	std::cout << BFS(date, used);
}