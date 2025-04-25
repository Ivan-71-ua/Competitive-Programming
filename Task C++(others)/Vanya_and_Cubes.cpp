#include <bits/stdc++.h>
#define ll long long
#define db double

int HROZNY(int t) {
	if(t == 1)
		return 1;
	return t + HROZNY(t - 1);
}



int main() {
	ll n;
	std::cin >> n;
	ll ans = 0;
	for (int i = 1; ; i++)
	{
		ans += HROZNY(i);
		if(ans > n) {
			std::cout << i - 1;
			break;
		}
	}
}