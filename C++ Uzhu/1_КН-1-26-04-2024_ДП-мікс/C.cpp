#include <bits/stdc++.h>

const int MAX_SIZE = 2010;
const int MOD = 301907;

std::string bracketSequence;
std::vector<std::vector<int>> memo(MAX_SIZE, std::vector<int>(MAX_SIZE, -1));
int sequenceLength;

int countValid(int position, int balance) {
	if (balance < 0) return 0;
	if (position == sequenceLength) return (balance == 0);
	if (memo[position][balance] != -1) return memo[position][balance];
	if (bracketSequence[position] == '(') {
		return memo[position][balance] = countValid(position + 1, balance + 1);
	} else if (bracketSequence[position] == ')') {
		return memo[position][balance] = countValid(position + 1, balance - 1);
	}
	return memo[position][balance] = (countValid(position + 1, balance - 1) + countValid(position + 1, balance + 1)) % MOD;
}

int main() {
	std::cin >> bracketSequence; 
	sequenceLength = bracketSequence.length();
	std::fill(memo.begin(), memo.end(), std::vector<int>(MAX_SIZE, -1));
	std::cout << countValid(0, 0) << std::endl; 
}
