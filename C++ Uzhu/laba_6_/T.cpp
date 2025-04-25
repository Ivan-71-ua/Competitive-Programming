#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k =0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int max_el = *max_element(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		if(arr[i] == max_el) {
			k++;
		}
	}
	cout << k;
}