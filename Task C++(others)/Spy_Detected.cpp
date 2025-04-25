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
		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
		}
		if(arr[0] != arr[1] && arr[1] == arr[2]) {
			cout << 1 << endl;
			continue;
		}
		else if(arr[k -1] != arr[k-2] && arr[k-2] == arr[k-3]) {
			cout << k << endl;
			continue;
		}
		else {
			for (int i = 1; i < k -1; i++)
			{
				if(arr[i -1] != arr[i] && arr[i] != arr[i + 1]) {
					cout << i + 1 << endl;
					continue;
				}
			}
		}
	}
	
}