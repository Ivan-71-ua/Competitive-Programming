#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	int cur = 1;
	std::stack<int> res;
	std::stack<int> wash;
	
	while(res.size() < n) {
		int a, b;
		std::cin >> a >> b;
		if(a == 1) {
			while(b--) {
				wash.push(cur);
				cur++;
			}
		} else {
			while (b--)
			{
				res.push(wash.top());
				wash.pop();
			}
		}
	}
	while(!res.empty()) {
		std::cout << res.top() << '\n';
		res.pop();
	}
}