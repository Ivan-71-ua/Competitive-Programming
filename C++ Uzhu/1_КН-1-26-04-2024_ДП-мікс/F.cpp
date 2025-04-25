#include <bits/stdc++.h>


const int MAX_DIAGONALS = 60;
const int MAX_ELEPHANTS = 3600;
long long dp[MAX_DIAGONALS][MAX_ELEPHANTS];


int CellsOnDiagonal(int diagonal) {
	if (diagonal % 2 == 1) {
		return (diagonal / 4) * 2 + 1;
	} else {
		return ((diagonal - 1) / 4) * 2 + 2;
	}
}

int main() {
	int boardSize, numElephants;
	while (std::cin >> boardSize >> numElephants, boardSize || numElephants) {
		if (numElephants > 2 * boardSize - 1) {
			std::cout << "0\n";
			continue;
		}
		for (int i = 0; i <= 2 * boardSize - 1; ++i) {
				dp[i][0] = 1;
		}
		dp[1][1] = 1; 
		for (int diagonal = 2; diagonal <= 2 * boardSize - 1; ++diagonal) {
			for (int elephant = 1; elephant <= numElephants; ++elephant) {
				int cellCount = CellsOnDiagonal(diagonal);
				if (elephant <= cellCount) {
					dp[diagonal][elephant] = dp[diagonal - 2][elephant] + 
							dp[diagonal - 2][elephant - 1] * (cellCount - elephant + 1);
				} else {
					dp[diagonal][elephant] = dp[diagonal - 2][elephant];
				}
			}
		}
		long long totalWays = 0;
		for (int i = 0; i <= numElephants; ++i) {
			if (i <= 2 * boardSize - 1 && numElephants - i <= 2 * boardSize - 2) {
				totalWays += dp[2 * boardSize - 1][i] * dp[2 * boardSize - 2][numElephants - i];
			}
		}
		std::cout << totalWays << "\n";
	}
}
