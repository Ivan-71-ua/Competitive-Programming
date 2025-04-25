#include <bits/stdc++.h>

#define MAX 110
#define INF 1061109567

std::string sequence;
int dp[MAX][MAX], splitPoint[MAX][MAX];

void printResult(int start, int end) {
	if (start > end) return;
	if (start == end) {
		if (sequence[start] == '(' || sequence[start] == ')') {
				std::cout << "()";
		} else {
				std::cout << "[]";
		}
	} else if (splitPoint[start][end] == -1) {
		std::cout << sequence[start];
		printResult(start + 1, end - 1);
		std::cout << sequence[end];
	} else {
		printResult(start, splitPoint[start][end]);
		printResult(splitPoint[start][end] + 1, end);
	}
}

int solve(int start, int end) {
	if (start == end) return 1;
	if (start > end) return 0;
	if (dp[start][end] != INF) return dp[start][end];

	if ((sequence[start] == '(' && sequence[end] == ')') || (sequence[start] == '[' && sequence[end] == ']')) {
		dp[start][end] = std::min(dp[start][end], solve(start + 1, end - 1));
	}

	for (int mid = start; mid < end; mid++) {
		int temp = solve(start, mid) + solve(mid + 1, end);
		if (temp < dp[start][end]) {
				splitPoint[start][end] = mid;
				dp[start][end] = temp;
		}
	}
	return dp[start][end];
}

int main() {
	std::cin >> sequence;
	int length = sequence.size();
	std::memset(dp, 63, sizeof(dp));
	std::memset(splitPoint, -1, sizeof(splitPoint));
	solve(0, length - 1);
	printResult(0, length - 1);
	std::cout << std::endl;
}
