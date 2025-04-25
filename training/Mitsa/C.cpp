#include <bits/stdc++.h>


int main() {
	// "hello";
	int n;
	std::string s;
	std::cin >> n >> s;
	int change = 0;
	for (int i = 1; i < s.size(); i++) {
		if(std::abs(s[i] - s[i - 1])) {
			change++;
		}
	}
	int st_monot = n - change;
	int st_change = n - change + 1;
	std::string tmp;
	int r, l;
	r = l = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if(i == 0) {
			std::cout << s[i] << ' ' << st_monot << '\n';
			if(s[i] == 'R')
				r += st_monot;
			else
				l += st_monot;
			st_monot--;
			tmp += s[i];
		} else {
			if(s[i] == s[i - 1]) {
				if(s[i] == 'L') {
					if(r + st_monot < l) {
						std::cout << "R" << ' ' << st_monot << '\n';
						r += st_monot;
					} else {
						std::cout << "L" << ' ' << st_monot << '\n';
						l += st_monot;
					}
				} else {
					if(l + st_monot < r) {
						std::cout << "L" << ' ' << st_monot << '\n';
						l += st_monot;
					} else {
						std::cout << "R" << ' ' << st_monot << '\n';
						r += st_monot;
					}
				}
				st_monot--;
			} else{
				std::cout << s[i] << ' ' << st_change << '\n';
				if(s[i] == 'R')
					r += st_change;
				else
					l += st_change;
				st_change++;
				tmp += s[i];
			}
		}
	}
}