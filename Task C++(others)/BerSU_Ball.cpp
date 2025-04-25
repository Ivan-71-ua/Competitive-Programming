#include <bits/stdc++.h>
#define ll long long

int main() {
	int g, m;
	std::cin >> m;
	std::vector<int> man;
	for (int i = 0; i < m; i++)
	{
		ll d;
		std::cin >> d;
		man.push_back(d);
	}
	std::cin >> g;
	std::vector<int> girl;
	for (int i = 0; i < g; i++)
	{
		ll d;
		std::cin >> d;
		girl.push_back(d);
	}
	ll ans = 0;
	std::sort(man.begin(), man.end());
	std::sort(girl.begin(), girl.end());
	for (int i = 0; i < m; i++)
	{
		auto iter = girl.cbegin();
		for (int p = 0; iter != girl.cend(); iter++, p++)
		{
			if(abs(man[i]  - girl[p]) <= 1) {
				ans++;
				girl.erase(iter);
				break;
			}
		}
	}
	std::cout << ans;
}