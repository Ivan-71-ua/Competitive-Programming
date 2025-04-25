#include <bits/stdc++.h>
using namespace std;



int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		int arr[n + 2];
		for (int i = 1; i <=n; i++)
		{
			cin >> arr[i];
		}
		arr[0] = 0;
		arr[n + 1] = k;
		int max = - 1;
		for (int i = 1; i < n + 2; i++)
		{
			if(i == n  + 1) {
				if(2 * (arr[i] - arr[i - 1]) > max) {
					max = 2 * (arr[i] - arr[i - 1]);
				}
			}
			else {
				if(arr[i] - arr[i-1] > max) {
					max = arr[i] - arr[i - 1];
				}
			}
			
		}
		cout << max << endl;
	}
	
}