#include <bits/stdc++.h>
#define INF LONG_MAX

const int MAX = 11;
std::vector<std::string> matrixIndex = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
std::vector<std::vector<long long>> minMultiplies(MAX, std::vector<long long>(MAX));
std::vector<std::vector<int>> splitPoint(MAX, std::vector<int>(MAX));
std::vector<int> dimensions(MAX + 1); 
std::string constructOptimalOrder(int i, int j) {
    if (i == j) return "A" + matrixIndex[i];
    return "(" + constructOptimalOrder(i, splitPoint[i][j]) + " x " + constructOptimalOrder(splitPoint[i][j] + 1, j) + ")";
}

long long findMinMultiplies(int i, int j) {
    if (minMultiplies[i][j] == INF) {
        for (int k = i; k < j; k++) {
            long long cost = findMinMultiplies(i, k) + findMinMultiplies(k + 1, j) + (long long)(dimensions[i - 1] * dimensions[k] * dimensions[j]);
            if (cost < minMultiplies[i][j]) {
                minMultiplies[i][j] = cost;
                splitPoint[i][j] = k;
            }
        }
    }
    return minMultiplies[i][j];
}

int main() {
    int numMatrices, testCase = 1;
    while (std::cin >> numMatrices && numMatrices) {
        for (int i = 1; i <= numMatrices; i++) {
            std::cin >> dimensions[i - 1] >> dimensions[i];
        }
        for (int i = 1; i <= numMatrices; i++) {
            for (int j = 1; j <= numMatrices; j++) {
                minMultiplies[i][j] = (i == j) ? 0 : INF;
                splitPoint[i][j] = 0;
            }
        }
        findMinMultiplies(1, numMatrices);
        std::cout << "Case " << testCase++ << ": ";
        if (numMatrices == 1) {
            std::cout << "(A1)";
        } else {
            std::cout << constructOptimalOrder(1, numMatrices);
        }
        std::cout << std::endl;
    }
}
