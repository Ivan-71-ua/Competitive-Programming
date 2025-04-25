#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		arr[i] += k;
	}
	int q = 0;
	for (int i = 0; i < n; i++)
	{
		if(arr[i] <= 5) {
			q++;
		}
	}
	cout << q / 3;
}