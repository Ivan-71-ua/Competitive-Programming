#include <bits/stdc++.h>
#define int long long

const int MAX = 1000000 + 200;


int32_t main() {
	int x, y, a, b;
	std::cin >> x >> y >> a >> b;
	std::unordered_map<int, int> used;
	std::queue<std::pair<int, int>> point;
	point.push({x, 0});
	used[x]++;
	while(!point.empty()) {
		std::pair<int, int> tmp = point.front();
		point.pop();
		if(tmp.first == y) {
			std::cout << tmp.second;
			return 0;
		}
		if(tmp.first + a <= MAX && !used.count(tmp.first + a)) {
			point.push({tmp.first + a, tmp.second + 1});
			used[tmp.first + a]++;
		}
		if(tmp.first - b > 0 && !used.count(tmp.first - b)) {
			point.push({tmp.first - b, tmp.second + 1});
			used[tmp.first - b]++;
		}
	}
	std::cout << -1;
	return 0;
}