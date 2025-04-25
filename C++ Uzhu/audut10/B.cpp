	#include <bits/stdc++.h>
	using namespace std;


	int Quantity_of_number(long long n) {
		if(n == 0) {
			return 0;
		}
		
		return n % 10 + Quantity_of_number(n / 10);
	}

	int main() {
		long long n;
		cin >> n;
		n = abs(n);
		cout << Quantity_of_number(n);
		
	}