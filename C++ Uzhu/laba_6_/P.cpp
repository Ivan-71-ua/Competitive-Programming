#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, min = 2 * pow(10,9) + 1, min1;
	min1 = min;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a < min) {
			min1 = min;
			min = a;
		}
		else if (a > min && a < min1) {
			min1 = a;
		}
	}
	cout << min  << " " << min1;
}