#include <bits/stdc++.h>

int main() {
	int age;
	std::cin >> age;
	int andrii_vaccines, boris_vaccines;
	std::cin >> andrii_vaccines >> boris_vaccines;
	if (age >= 18) {
		if (andrii_vaccines == 2) {
				std::cout << "Yes" << std::endl;
		} else {
				std::cout << "No" << std::endl;
		}
	} else {
		if (boris_vaccines == 2) {
				std::cout << "Yes" << std::endl;
		} else {
				std::cout << "No" << std::endl;
		}
	}
	return 0;
}