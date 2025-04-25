#include <bits/stdc++.h>

#define ll long long



int32_t main() {
	ll n;
	std::cin >> n;
	std::vector<int> a(n + 1), b(n + 1);
	for (ll i = 1; i <= n; ++i)
		std::cin >> a[i];
	std::vector<int> s;
	s.push_back(a[1]);
	ll j = 1;
	for (ll i = 2; i <= n; ++i) {
		if (a[i] < s.back())
			s.push_back(a[i]);
		else {
			while (!s.empty() && a[i] > s.back()) {
					b[j++] = s.back();
					s.pop_back();
			}
			s.push_back(a[i]);
		}
	}
	while (!s.empty()) {
		b[j++] = s.back();
		s.pop_back();
	}
	--j;
	ll i = 1;
	for (i = 1; i < j; ++i) {
		if (b[i] + 1 == b[i + 1])
			continue;
		else
			break;
	}
	if (i == j)
		std::cout << "YES";
	else
		std::cout << 0;
}
