#include <bits/stdc++.h>


int main() {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	int n, k = 315, sum = 0;
	std::string ans;
	std::cin >> n;
	while(sum <= n) {
		std::cout << "? " << sum << std::endl;
		std::cin >> ans;
		if(ans == "survived")
			sum += k;
		else {
			break;
		}
	}
	sum -= k;
	while(true) {
		std::cout << "? " << sum << std::endl;
		std::cin >> ans;
		if(ans == "crashed") {
			std::cout << "! " << sum -1  <<  std::endl;
			break;
		}
		sum++;
	}
}
