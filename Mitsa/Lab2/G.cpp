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



std::vector<int> parent;
std::vector<int> rank;

int find(int x) {
	if (parent[x] != x)
		return parent[x] = find(parent[x]);
	return x;
}

void make_union(int x, int y) {
	int px = find(x);
	int py = find(y);
	if (px == py) {
		rank[px]++;
	}
	else {
		parent[py] = px;
		rank[px] += rank[py];
	}
}


int main() {
	int k;
	std::cin >> k;
	while (k--) {
		int n;
		std::cin >> n;
		parent.resize(n * 2 +3);
		rank.resize(n * 2 +3);
		for (int i = 1; i <= n * 2; i++) {
			rank[i] = 0;
			parent[i] = i;
		}
		for (int i = 0; i < n; i++) {
			int a, b;
			std::cin >> a >> b;
			make_union(a, b);
		}
		int f = 1;
		for (int i = 1; i <= n * 2; i++) {
			if (rank[i] > 1) {
				f = 0;
				break;
			}
		}
		if (f) {
			std::cout << "possible\n";
		}
		else {
			std::cout << "impossible\n";
		}
		parent.clear();
		rank.clear();
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
