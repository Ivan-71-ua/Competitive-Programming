#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

bool is_prime(int b) {
	if(b == 1)
		return false;
	if(b == 2)
		return true;
	for (int i = 2; i < b; i++)
	{
		if(b % i == 0)
			return false;
	}
	return true;
}

int main () {
	int l, r;
	std::cin >> l >> r;
	int ans = 0;
	for (int i = l; i <= r; i++)
	{
		if(is_prime(i))
			ans++;
	}
	std::cout <<  ans;
}