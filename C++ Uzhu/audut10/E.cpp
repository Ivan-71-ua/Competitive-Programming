#include <bits/stdc++.h>
using namespace std;

int Quantity_of_number(int n, int k) {
	if(k == 0) {
		return n;
	}
	return Quantity_of_number(k, n % k);
}

int main() {
	int l;
	cin >> l;
	int arr[l];
	for (int i = 0; i < l; i++)
	{
		cin >> arr[i];
	}
	int p = Quantity_of_number(arr[0], arr[1]);
	for (int i = 2; i < l - 1; i++)
	{
		int c = Quantity_of_number(arr[i], arr[i + 1]);
		if(c < p) {
			p = c;
		}
	}
	cout << p;
}