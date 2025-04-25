#include <bits/stdc++.h>



int main() {
	int r, g, b;
	std::string cl;
	std::cin >> r >> g >> b >> cl;
	if(cl == "Red") {
		std::cout << std::min(g, b);
	} else if( cl == "Green") {
		std::cout << std::min(r, b);
	} else {
		std::cout << std::min(r, g);
	}
}