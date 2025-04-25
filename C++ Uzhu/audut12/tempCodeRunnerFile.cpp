#include <bits/stdc++.h>


void HROZNY() {
	std::string s;
	std::cin >> s;
	std::string m = "", n = "";
	std::sort(s.begin(), s.end());
	m = m + s;
	std::sort(s.begin(), s.end(), std::greater());
	n = n + s;
	std::cout << std::stoi(n) + std::stoi(m);
}


int main() {
	HROZNY();
}