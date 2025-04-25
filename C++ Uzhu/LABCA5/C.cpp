#include <bits/stdc++.h>
using namespace std;


int main() {
	long long n, max = -1;
	cin >> n;
	while (n != 0)
	{
		int c;
		c = n % 10;
		n = n / 10;
		if(c > max) {
			max = c;
		}
	}
	cout << max;
}