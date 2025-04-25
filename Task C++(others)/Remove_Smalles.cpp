#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		int arr[k];
		bool ans = true;
		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];	
		}
		sort(arr, arr + k);
		for (int i = 0; i < k - 1; i++)
		{
			if(arr[i + 1] - arr[i] > 1) {
				ans = false;
				break;
			}
			
		}
		if(ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
}