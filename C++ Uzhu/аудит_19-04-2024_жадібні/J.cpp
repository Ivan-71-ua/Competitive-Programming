#include <bits/stdc++.h>


int main() {
	std::string res;
	int n;
	std::cin >> n;
	while(n != 1) {
		if(n % 3 == 0) {
			n /= 3;
			res += '3';
		}
		else {
			n--;
			res += '1';
		}
	}
	std::reverse(res.begin(), res.end());
	std::cout << res;
}