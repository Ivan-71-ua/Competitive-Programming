#include <bits/stdc++.h>



#define MAX 300
#define INF 1061109567

std::vector<int> frequencies(MAX+1), partialSums(MAX+1);
std::vector<std::vector<int>> optimalCost(MAX+1, std::vector<int>(MAX+1, INF));

int weight(int start, int end) {
	if (start > end) return 0;
	return partialSums[end] - (start > 0 ? partialSums[start - 1] : 0);
}

int computeOptimalCost(int start, int end) {
	if (start > end) return 0;
	if (optimalCost[start][end] == INF) {
		for (int k = start; k <= end; k++) {
				int cost = computeOptimalCost(start, k - 1) + computeOptimalCost(k + 1, end) +
							weight(start, k - 1) + weight(k + 1, end);
				if (cost < optimalCost[start][end]) {
					optimalCost[start][end] = cost;
				}
		}
	}
	return optimalCost[start][end];
}

int main() {
	int n;
	while (std::cin >> n) {
		// Initialize the optimal cost matrix and frequency input
		for (int i = 0; i <= n; i++) {
				std::vector<int>(n + 1, INF).swap(optimalCost[i]);
				if (i <= n) {
					optimalCost[i][i] = 0;
				}
		}
		// Read frequencies
		for (int i = 1; i <= n; i++) {
				std::cin >> frequencies[i];
		}
		// Compute partial sums
		partialSums[0] = 0;
		for (int i = 1; i <= n; i++) {
				partialSums[i] = partialSums[i - 1] + frequencies[i];
		}
		// Compute the optimal cost from the first to the last element
		computeOptimalCost(1, n);
		// Output the result
		std::cout << optimalCost[1][n] << std::endl;
	}
}
