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



std::vector<int> used;
std::vector<std::vector<int>> list;
std::vector<int>res;

void dfs(int v, int& flag) {
	if (flag) return;
	used[v] = 1;
	for (auto next : list[v]) {
		if (used[next] == 0) {
			dfs(next, flag);
		}
		if (used[next] == 1) {
			flag = 1;
			return;
		}
	}
	used[v] = 2;
	res.push_back(v);
}

int main() {
	int n, m;
	std::cin >> n >> m;
	list.resize(n);
	used.resize(n, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		list[a  - 1].push_back(b - 1);
	}
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			dfs(i, flag);
		}
	}
	if (!flag) {
		std::reverse(res.begin(), res.end());
		for (auto n : res) {
			std::cout << n + 1 << ' ';
		}
	}
	else {
		std::cout << -1;	
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
