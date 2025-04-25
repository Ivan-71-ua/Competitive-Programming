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
	
	for (int i = 0; i < n; i++)
	{
		if(max < arr[i]) {
			max = arr[i];
			k = i;
		}
	}
	cout << max << ' ' << k +1;
}