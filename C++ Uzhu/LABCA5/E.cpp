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
	int min = min_element(arr, arr + n) - arr;
	int c = arr[min];
	arr[min] = arr[0];
	arr[0] = c;
	for (int i = 0; i < n; i++)
	{
		cout <<  arr[i] << " ";
	}
}