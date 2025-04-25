#include <bits/stdc++.h>

int main() {
	int n, x;
	std::stack<int> s;
	while (std::cin >> n && n != 0) {
		while (std::cin >> x && x != 0) {
				int cur = 1;
				bool ok = true;
				while (!s.empty())
					s.pop();
				for (int i = 1; i < n; ++i) {
					while (cur <= x) {
						s.push(cur++);
					}
					if (s.top() != x)
						ok = false;
					s.pop();
					std::cin >> x;
				}
			std::cout << (ok ? "Yes" : "No") << std::endl;
		}
		if (n != 0)
			std::cout << std::endl;
	}
}
