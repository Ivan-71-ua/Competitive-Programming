#include <bits/stdc++.h>

int main() {
	int n, x;
	std::cin >> n >> x; 
	std::set<int> s; 
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a; 
		s.insert(a); 
	}
	bool is = false;
	for (int a : s) { 
		if (s.find(a + x) != s.end()) {
			is = true;
			break;
		}
	}
	if(is) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}
}
