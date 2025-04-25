#include <bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	while (t--)
	{
		std::string s;
		int n;
		std::cin  >> n >> s;
		if( n == 5) {
			if(s.find('T') != -1 && s.find('i') != -1 && s.find('m') != -1 && s.find('u') != -1 && s.find('r') != -1) {
			std::cout << "YES\n";
			}
			else {
				std::cout << "NO\n";
			}
		} else {
			std::cout << "NO\n";
		}
		
	}
	
}