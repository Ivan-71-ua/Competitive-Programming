#include <bits/stdc++.h>


void HROZNY() {
	std::string s;
	std::cin >> s;
	std::string m = "", n = "";
	if(s.find("0") == std::string::npos) {
		std::sort(s.begin(), s.end());
		m = m + s;
		reverse(s.begin(),s.end());
		n = n + s;
		
	} else {
		std::sort(s.begin(), s.end(), std::greater());
		m = m + s;
		reverse(s.begin(),s.end());
		if(std::count(s.begin(), s.end(), '0') == 1) {
			s[0] = s[1];
			s[1] = '0';
			n = n + s;
		}
		else {
			n = n + m;
		}
	}
	std::cout << std::stoi(n) + std::stoi(m);
}


int main() {
	HROZNY();
}