#include <bits/stdc++.h>
using namespace std;


int main()
{
	int k, p;
	cin >> k >> p;
	for (int i = 0; i < p; i++) {
		int c = k % 10;
		if(c != 0) {
			k--;
		}
		else {
			k /= 10;
		}
	}
	cout << k;
}