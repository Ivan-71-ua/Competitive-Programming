	#include <iostream>
	#include<string>
	#include <algorithm>
	using namespace std;

	int main() {
		long long n;
		cin >> n;
		int k = 0;
		while(n != 0) {
			int c;
			c = n % 10;
			n = n / 10;
			if(c > k) {
				k = c;
			}
		}
		cout << k;
	}