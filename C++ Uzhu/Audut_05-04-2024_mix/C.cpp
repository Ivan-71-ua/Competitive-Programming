#include <bits/stdc++.h>


int main() {
	int n, k;
	std::cin >> n >> k; 
	std::set<long long> s; 
	std::vector<int> m(n);
	for (int i = 0; i < n; i++) {
		std::cin >> m[i]; 
	}
	s.insert(0); 
	for (int i = 0; i < k; i++) {
		auto y = *s.begin(); 
		s.erase(s.begin()); 
		for (int j = 0; j < n; j++) {
			s.insert(y + m[j]); 
		}
	}
	std::cout << *s.begin() << std::endl; 
	return 0;
}
