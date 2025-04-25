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
	int min = *min_element(arr, arr + n);
	int max = *max_element(arr, arr + n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if(arr[i] != min && arr[i] != max) {
			sum += arr[i];
		}
	}
	cout << sum;
}