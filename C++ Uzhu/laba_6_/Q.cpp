#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, min = pow(10,5) + 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a < min) {
			min = a;
	}
	}
	cout << min;
}