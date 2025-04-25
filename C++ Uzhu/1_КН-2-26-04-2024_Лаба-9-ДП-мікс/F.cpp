#include <bits/stdc++.h>
#define MAX 101
#define INF 0x3F3F3F3F

int dp[MAX][MAX];
std::string input;

int minInsertionsForPalindrome(int start, int end) {
	if (start > end) return 0; 
	if (start == end) return 1; 
	if (dp[start][end] != INF) return dp[start][end]; 

	int &result = dp[start][end];
	result = INF;
	if (input[start] == input[end]) {
		result = std::min(result, minInsertionsForPalindrome(start + 1, end - 1));
	}
	for (int split = start; split < end; split++) {
		result = std::min(result, minInsertionsForPalindrome(start, split) + minInsertionsForPalindrome(split + 1, end));
	}
	return result; 
}

int main() {
	std::cin >> input; 
	std::memset(dp, INF, sizeof(dp)); 
	int finalResult = minInsertionsForPalindrome(0, input.size() - 1); 
	std::cout << finalResult << std::endl; 
}
