// code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <bits/stdc++.h>
//#define int long long


std::vector<int> used;
std::vector<std::vector<int>> list;
std::vector<int>weight;

int dfs(int v) {
	used[v] = 1;
	int val = weight[v];
	for (auto next : list[v]) {
		if (!used[next]) {
			val += dfs(next);
		}
		
	}
	return val;
	
}

int32_t main() {
	std::string s;
	std::getline(std::cin, s);
	std::stringstream parses(s);
	int tmp;
	while (parses >> tmp) {
		weight.push_back(tmp);
	}
	used.resize(weight.size());
	list.resize(weight.size());
	for (int i = 0; i < weight.size(); i++) {
		parses.clear();
		std::getline(std::cin, s);
		parses.str(s);
		while (parses >> tmp) {
			list[i].push_back(tmp - 1);
		}
	}
	std::cout << dfs(0);
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
