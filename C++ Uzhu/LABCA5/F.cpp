#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, j, max = -101;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if(arr[i] >= max) {
			j = i;
			max = arr[i];
		}
	}
	swap(arr[n - 1], arr[j]);

	for (int i = 0; i < n; i++)
	{
		cout <<  arr[i] << " ";
   }
}