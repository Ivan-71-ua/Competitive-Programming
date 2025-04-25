#include <bits/stdc++.h>
#define ll long long
#define db double

ll Foo(ll n) {
	
	return ceil(log(n) / log(3));
}


int main() {
	ll g;
	std::cin >> g;
	std::cout << Foo(g);
}