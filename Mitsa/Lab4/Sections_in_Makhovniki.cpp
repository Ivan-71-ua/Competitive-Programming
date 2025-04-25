// code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <bits/stdc++.h>




int32_t main() {
	int n;
	std::cin >> n;
	std::set<int, std::greater<>> max_next;
	std::vector<std::vector<int>> list(n);
	std::vector<int> degree(n);
	std::vector<int> order;

	for (int i = 0; i < n; i++) {
		int k;
		std::cin >> k;
		for (int j = 0; j < k; j++) {
			int next;
			std::cin >> next;
			list[i].push_back(next - 1); 
			degree[next - 1]++;
		}
	}
	for (int i = 0; i < n; i++)
		if (degree[i] == 0) max_next.insert(i);

	while (!max_next.empty())
	{
		int v = *max_next.begin();
		max_next.erase(max_next.begin());
		order.push_back(v);
		for (auto nx: list[v])
		{
			degree[nx]--;
			if (degree[nx] == 0) max_next.insert(nx);

		}
	}
	std::reverse(order.begin(), order.end());

	for (int i : order) {
		std::cout << i + 1 << ' '; 
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
