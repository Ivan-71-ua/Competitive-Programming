#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	double k = 0;
	cin >> n;
	double arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if(abs(arr[i]) > abs(k)) {
			k = arr[i];
		}
	}
	cout << fixed << setprecision(2);
	cout << abs(k);
}