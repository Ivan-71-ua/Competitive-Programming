#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sum ^= i;
	}
	
	for (int i = 0; i < n - 1; i++) {
		int c;
		cin >> c;
		sum  ^= c;
	}
	cout << sum;
}