#include <bits/stdc++.h>


int main() {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	int n, k = 315, sum = 0;
	std::cin >> n;
	while(sum <= n) {
		std::cout << "? " << sum << std::endl;
		std::string an;
		std::cin >> an;
		if(an == "survived")
			sum += k;
		else {
			break;
		}
	}
	sum -= k;
	while(true) {
		std::cout << "? " << sum << std::endl;
		std::string an;
		std::cin >> an;
		if(an == "crashed") {
			std::cout << "! " << sum -1  <<  std::endl;
			break;
		}
		sum++;
	}
}
