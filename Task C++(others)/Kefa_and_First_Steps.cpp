#include <bits/stdc++.h>
using namespace std;




int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int k = 1, max = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] >= arr[i-1]) {
			k++;
			if(max < k) {
				max = k;	
			}
		}
		else {
			k = 1;
		}
	}
	cout << max;
}