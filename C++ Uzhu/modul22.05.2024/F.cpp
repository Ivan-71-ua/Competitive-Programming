#include <bits/stdc++.h>

bool isPalindrome(int hh, int mm) {
	std::string h = (hh < 10 ? "0" : "") + std::to_string(hh);
	std::string m = (mm < 10 ? "0" : "") + std::to_string(mm);
	return h[0] == m[1] && h[1] == m[0];
}

void incrementTime(int &hh, int &mm) {
	mm++;
	if (mm == 60) {
		mm = 0;
		hh++;
		if (hh == 24) {
			hh = 0;
		}
	}
}

int main() {
	std::string time;
	std::cin >> time;
	int hh = std::stoi(time.substr(0, 2));
	int mm = std::stoi(time.substr(3, 5));
	do {
		incrementTime(hh, mm);
	} while (!isPalindrome(hh, mm));
	std::cout << std::setw(2) << std::setfill('0') << hh << ":" << std::setw(2) << std::setfill('0') << mm << '\n';
}
