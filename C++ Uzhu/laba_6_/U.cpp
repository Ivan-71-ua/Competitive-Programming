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
	int max = -101, max1 = -101;
	for (int i = 0; i < n;i++) {
		if(arr[i] >= max) {
			max1 = max;
			max = arr[i];
		}
		else if(arr[i] > max1 && arr[i] < max) {
			max1 = arr[i];
		}
	}
	cout << max1 + max;
}