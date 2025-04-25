#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x, y, n;
		cin >> x >> y >> n;
		if(n % x == y) {
			cout << n << endl;
		}
		else {
			if((n % x) < y) {
				cout << n - ((n % x) + (x - y)) << endl;
			}
			else {
				cout << n - ((n % x) - y) << endl;
			}
		}
	}
}