#include <bits/stdc++.h>
using namespace std;



int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int arr[n]{};
		int arr1[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr1[i];
		}
		int k = 0;
		while (*max_element(arr, arr + n) != *max_element(arr1, arr1 + n)) {
			for (int i = 0; i < n; i++)
			{
				if(arr[i] != arr1[i]) {
					arr[i]++;
				}
				if(arr[i] == arr1[i]) {
					int j = i;
					while(arr[j] == arr1[j]) {
						j++;
					}
					arr[j]++;
					i = j;
					k++;
				}
			}
			
		}
		cout << k;
	}
}