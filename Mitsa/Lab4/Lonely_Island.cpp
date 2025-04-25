// code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <sstream>
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

#define EPS 1e-9


int main() {
	int n, m, r;
	std::cin >> n >> m >> r;
	std::vector<std::vector<int>> list(n + 1);
	std::vector<int> in(n + 1, 0), out(n + 1, 0);
	std::deque<int> q;
	std::vector<double> equal(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		list[a].push_back(b);
		out[a]++;
		in[b]++;
	}


	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) q.push_back(i);
	}

	equal[r] = 1;

	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		for (auto next : list[v]) {
			equal[next] += equal[v] / out[v];
			in[next]--;
			if (in[next] == 0) q.push_back(next);
		}
	}

	double res = 0;
	for (int i = 1; i <= n; i++) {
		if (out[i] == 0 && equal[i] > res) {
			res = equal[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (out[i] == 0 && std::fabs(equal[i] - res) <= EPS) {
			std::cout << i << " ";
		}
	}

	return 0;
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
