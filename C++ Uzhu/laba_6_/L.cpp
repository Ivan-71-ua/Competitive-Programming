#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, max = 0;
	cin >> n;
	n = abs(n);
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