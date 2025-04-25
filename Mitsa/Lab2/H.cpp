// code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <climits>
#include <string>




std::vector<bool> used;
std::vector<std::vector<int>> list;
void dfs(int v, int& count) {
	used[v] = true;
	count++;
	for (auto next : list[v])
		if (!used[next])
			dfs(next, count);
}


int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> weba_play;
	std::vector<std::pair<int, int>> webb_play;
	used.resize(n);
	list.resize(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		weba_play.push_back({ a, i });
		webb_play.push_back({ b, i });
	}
	std::sort(weba_play.begin(), weba_play.end());
	std::sort(webb_play.begin(), webb_play.end());
	for (int i = 1; i < n; i++) {
		list[weba_play[i].second].push_back(weba_play[i - 1].second);
		list[webb_play[i].second].push_back(webb_play[i - 1].second);
	}
	std::vector<int> res(n);
	int count = 0;
	for (int i = 0; i < n; i++) {
		int v = weba_play[i].second;
		if (!used[v]) {
			dfs(v, count);
		}
		res[v] = count -1;
	}
	for (auto now : res) {
		std::cout << now << '\n';
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
