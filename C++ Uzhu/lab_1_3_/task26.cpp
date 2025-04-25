	#include <iostream>
	#include<string>
	#include <algorithm>
	using namespace std;

	int main() {
		long long n, a;
		cin >> n >> a;	
		int k = 0;
		n = abs(n);
		while(n != 0) {
			int c;
			c = n % 10;
			n = n / 10;
			if(a == c) {
				k++;
			}
		}
		cout << k;
	}