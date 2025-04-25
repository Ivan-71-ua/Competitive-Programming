#include <bits/stdc++.h>
using namespace std;



int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int max_v = *max_element(arr, arr + n);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		k += max_v - arr[i];
	}
	cout << k;
}