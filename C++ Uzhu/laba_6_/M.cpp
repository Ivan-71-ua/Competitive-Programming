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
	int max = *max_element(arr, arr + n);
	int min = *min_element(arr, arr + n);
	for (int i = 0; i < n;i++) {
		if(arr[i]== max) {
			cout << min << " ";
		}
		else {
			cout << arr[i] << " ";
		}
	}
}