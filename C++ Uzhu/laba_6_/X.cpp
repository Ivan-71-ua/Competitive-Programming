#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, max = -101, k = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int min_el = *min_element(arr, arr + n);
	int max_el = *max_element(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		if(arr[i] == min_el) {
			cout << max_el << " ";
		}
		else if(arr[i] == max_el) {
			cout << min_el << " ";
		}
		else {
			cout << arr[i] << " ";
		}
	}
}