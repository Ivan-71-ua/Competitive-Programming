#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	int k = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int min = *min_element(arr, arr + n);
	int max = *max_element(arr, arr + n);
	cout << min + max;
}