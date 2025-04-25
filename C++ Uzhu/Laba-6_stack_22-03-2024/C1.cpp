#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n;
	std::cin >> n;
	std::stack<int> right;
	for (int i = 1; i <= n; i++)
	{
		right.push(i);
	}

	std::stack<int> now;
	for (int i = 0; i < n; i++)
	{
		int k;
		std::cin >> k;
		if(right.top() == k) {
				right.pop();
		} else {
				now.push(k);
		}
	}
	while(!right.empty() && !now.empty() && right.top() == now.top()) {
		right.pop();
		now.pop();
	}
	if(now.empty() && right.empty())
		std::cout << "YES";
	else
		std::cout << "NO";
}