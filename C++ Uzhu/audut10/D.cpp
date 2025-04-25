	#include <bits/stdc++.h>
	using namespace std;

	long long Quantity_of_number(int n) {
		long long c;
		if(n == 0) {
			return 0;
		}
		cin >> c;
		return c + Quantity_of_number(n - 1);
	}

	int main() {
		cout << Quantity_of_number(2);
		
	}