#include <bits/stdc++.h>
using namespace std;


int main() {
	int a, b, c, sum = 0;
	cin >> a >> b >> c;
	for (int i = 1; i <= c; i++)
	{
		sum = sum + a * i;
	}
	if (b - sum < 0) {
		cout << abs(b - sum);
	}
	else {
		cout << 0;
	}
	
}