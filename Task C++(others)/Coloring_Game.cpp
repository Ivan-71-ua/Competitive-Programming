#include<bits/stdc++.h>

void dfs(int v, std::vector<std::vector<int>> &graf, std::vector<int> &color, bool &dubles) {
	for (auto next: graf[v])
	{
		if(!color[next]) {
			color[next] = 3 - color[v];
			dfs(next, graf, color, dubles);
		} else if(color[v] + color[next] != 3) {
			dubles = true;
		}
	}
}

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<int>> graf(n + 1);
		std::vector<int> color(n + 1);
		color[1] = 1;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			std::cin >> a >> b;
			graf[a].push_back(b);
			graf[b].push_back(a);
		}
		bool dubles = false;
		dfs(1, graf, color, dubles);
		if(dubles) {
			std::cout << "Alice" << std::endl;
			for (int i = 0; i < n; i++)
			{
				std::cout << 1 << ' ' << 2 << std::endl;
				int ver, color;
				std::cin >> ver >> color;
			}
		} else {
			std::cout << "Bob" << std::endl;
			std::vector<int> part1, part2;
			for (int i = 1; i <= n; i++)
			{
				if(color[i] == 1) {
					part1.push_back(i);
				} else {
					part2.push_back(i);
				}
			}
			int col1, col2;
			for (int i = 0; i < n; i++)
			{
				std::cin >> col1 >> col2;
				if((col1 == 1 || col2 == 1) && !part1.empty()) {
					std::cout << part1.back() << ' ' << 1 << std::endl;
					part1.pop_back();
				} else if((col1 == 2 || col2 == 2) && !part2.empty()) {
					std::cout << part2.back() << ' ' << 2 << std::endl;
					part2.pop_back();
				} else if (part1.empty()) {
					int chose = (col1 == 1 ? col2 : col1);
					std::cout << part2.back() << ' ' << chose << std::endl;
					part2.pop_back();
				} else {
					int chose = (col1 == 2 ? col2 : col1);
					std::cout << part1.back() << ' ' << chose << std::endl;
					part1.pop_back();
				}
			}
		}
	}
}