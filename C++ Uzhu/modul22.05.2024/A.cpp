#include <bits/stdc++.h>

int main() {
	int t;
	int k = 1;
	std::cin >> t;
	while(t--) {
		std::set<int> res;
		for (int i = 0; i < 3; i++)
		{
			int tmp;
			std::cin >> tmp;
			res.insert(tmp);
		}
		std::cout << "Case " << k << ": " << *++res.begin() << '\n';
		k++;
	}
	
	
}