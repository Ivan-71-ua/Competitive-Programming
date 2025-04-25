#include <bits/stdc++.h>

void multiply(std::vector<int>& result, int multiplier) {
	int carry = 0;
	for (size_t i = 0; i < result.size(); i++) {
		int product = result[i] * multiplier + carry;
		result[i] = product % 10; 
		carry = product / 10;  
	}
	
	while (carry > 0) {
		result.push_back(carry % 10);
		carry /= 10;
	}
}

std::vector<int> factorial(int n) {
	std::vector<int> result(1, 1);  
	for (int i = 2; i <= n; i++) {
		multiply(result, i);  
	}
	return result;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> result = factorial(n);
	for (auto it = result.rbegin(); it != result.rend(); it++) {
		std::cout << *it;
	}
	std::cout << std::endl;
}
