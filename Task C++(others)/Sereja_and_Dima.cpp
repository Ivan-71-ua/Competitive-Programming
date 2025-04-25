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
	int S = 0, D = 0;
	for (int i = 0, j = n -1, o = 0; o < n;o++)
	{
		if(o % 2 == 0) {
			if(arr[i] > arr[j]) {
				S += arr[i];
				i++;
			}
			else {
				S += arr[j];
				j--;
			}
		}
		else if(o % 2 != 0) {
			if(arr[i] > arr[j]) {
				D += arr[i];
				i++;
			}
			else {
				D += arr[j];
				j--;
			}
		}
	}
	cout << S << " " << D;
}