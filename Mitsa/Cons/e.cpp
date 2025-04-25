#include <bits/stdc++.h>


int main() {
	std::string num1, num2;
	std::cin >> num1 >> num2;
	int q1 = -1, q2 = -1;
	for(int i = 0; i < num1.size(); i++) {
		if(num1[i] == '.') {
			q1 = i;
			break;
		}
	}
	for(int i = 0; i < num2.size(); i++) {
		if(num2[i] == '.') {
			q2 = i;
			break;
		}
	}
	int first1 = std::stoi(num1.substr(0, q1));
	int second1 = std::stoi(num1.substr(q1 + 1));
	int first2 = std::stoi(num2.substr(0, q2));
	int second2 = std::stoi(num2.substr(q2 + 1));
	if(first1 > first2 || (first1 == first2 && second1 > second2)) {
		std::cout << "Number " << num1 << " is greater than " << num2 << '\n';
	} else if(first1 < first2 || (first1 == first2 && second1 < second2)) {
		std::cout << "Number " << num2 << " is greater than " << num1 << '\n';
	} else {
		std::cout << "Numbers " <<num1 << " and " << num2 << " are equal";
	}
}