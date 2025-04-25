#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int f, s, g, u, d;
	std::cin >> f >> s >> g >> u >> d;
	std::vector<bool> visited(f + 1, false);
	std::queue<std::pair<int, int>> q; 
	q.push({s, 0});
	visited[s] = true;
	while (!q.empty()) {
		auto [currentPos, currentSteps] = q.front();
		q.pop();
		if (currentPos == g) {
			std::cout << currentSteps;
			return 0;
		}
		if (currentPos + u <= f && !visited[currentPos + u]) {
			q.push({currentPos + u, currentSteps + 1});
			visited[currentPos + u] = true;
		}
		if (currentPos - d >= 1 && !visited[currentPos - d]) {
			q.push({currentPos - d, currentSteps + 1});
			visited[currentPos - d] = true;
		}
	}
	std::cout << "use the stairs";
	return 0;
}
