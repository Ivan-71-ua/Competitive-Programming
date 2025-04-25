#include <bits/stdc++.h>


int main() {
	int res = 0;
	int n;
	std::cin >> n;
	while(n != 1) {
		if(n % 3 == 0)
			n /= 3;
		else {
			n--;
		}
		res++;
	}
	std::cout << res;
}