#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, j, min = 101, k = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if(arr[i] < min ) {
			min = arr[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] + abs(min / 2) <<  " ";
	}
}