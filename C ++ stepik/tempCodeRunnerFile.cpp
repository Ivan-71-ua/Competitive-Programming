
#include <bits/stdc++.h>


int main() {
	int n;
	std::cin >> n;
	std::deque<int> v, c, r;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	int a, b;
	while(std::cin >> a >> b) {
		if(a == 1) {
			while(b--) {
				int x= v.front();
				v.pop_front();
				c.push_back(x);
			}
		} else {
			while(b--) {
				int x = c.back();
				c.pop_back();
				v.push_front(x);
			}
		}
	}
	for(auto i : v) {
		std::cout << i << '\n';
	}
}
