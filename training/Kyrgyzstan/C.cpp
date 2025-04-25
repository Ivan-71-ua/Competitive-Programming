#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, char>> point;
	for (int i = 0; i < n; i++)
	{
		int s, f;
		std::cin >> s >> f;
		point.push_back({s, 's'});
		point.push_back({f, 'f'});
	}
	std::stable_sort(point.begin(), point.end());
	long long res = 0;
	std::stack<int> dist;
	for (int i = 0; i < n * 2; i++)
	{
		if(point[i].second == 's') {
			dist.push(point[i].first);
		} else {
			if(dist.size() == 1) {
				res += abs(point[i].first - dist.top());
			}
			dist.pop();
		}
	}
	std::cout <<  res;
}