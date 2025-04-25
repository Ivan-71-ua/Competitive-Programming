#include <bits/stdc++.h>
#define ll long long


int Quantity_of_number(long long n) {
		if(n == 0) {
			return 1;
		}
		
		return n % 10 * Quantity_of_number(n / 10);
	}


int main() {
	ll n;
	while (std::cin >> n)
	{
		int cnt = 0;
		while(n > 9)
		{
			cnt++;
			n = Quantity_of_number(n);
		}
		std::cout << cnt << '\n';
	}
}