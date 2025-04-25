#include <bits/stdc++.h>
#define ll long long


bool isPrime(int n){
	if(n == 2) {
		return true;
	}
	else {
		for (int i = 2; i <= sqrt(n); i++)
		{
			if(n % i == 0) {
				return false;
				break;
			}
		}
		return true;
	}
}
int Next_prime(int k) {
	for (int i = k + 1; ;i++)
	{
		if(isPrime(i)) {
			return i;
		}
	}
	
}
int main()
{
	int a, b;
	std::cin >> a >> b;
	if(a < b && b == Next_prime(a)) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
}