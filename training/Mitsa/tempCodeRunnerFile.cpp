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
	for (int i = 0; i < s.size(); i++)
	{
		if(i==0) {
			std::cout << s[i] << ' ' << st_monot-- << '\n';
			tmp += s[i];
		} else {
			if(s[i] == s[i - 1]) {
				if(tmp.back() == 'L') {
					std::cout << 'R' << ' ' << st_monot-- << '\n';
					tmp += 'R';
				} else {
					std::cout << 'L' << ' ' << st_monot-- << '\n';
					tmp += 'L';
				}
			} else{
				std::cout << s[i] << ' ' << st_change++ << '\n';
				tmp += s[i];
			}
		}
	}
}