	#include <iostream>
	#include<string>
	#include <algorithm>
	using namespace std;

	int main() {
		long long n;
		cin >> n;	
		int k = 1;
		n = abs(n);
		while(n != 0) {
			int c;
			c = n % 10;
			n = n / 10;
			if(c != 0) {
				k = k * c;
			}
		}
		cout << k;
	}