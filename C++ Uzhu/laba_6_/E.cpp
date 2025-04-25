#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if(arr[i] % 2 == 0) {
			k++;
		}
	}
	if(k == 0) {
		cout << "NO";
	}
	else {
		cout << k << endl;
		for (int i = n - 1; i >= 0; i--)
	{
		if(arr[i] % 2 == 0) {
			cout << arr[i] << " ";
		}
	}
	}
}