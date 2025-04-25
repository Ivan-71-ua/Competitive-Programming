#include <bits/stdc++.h>
using namespace std;


int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int arr[6];
	for (int i = 0; i < 6; i++)
	{
		if(i == 0) {
			arr[i] = a * b * c;
		}
		if(i == 1) {
			arr[i] = a + b + c;
		}
		if(i == 2) {
			arr[i] = a + b * c;
		}
		if(i == 3) {
			arr[i] = a * b + c;
		}
		if(i == 4) {
			arr[i] = (a + b) * c;
		}
		if(i == 5) {
			arr[i] = a * (c + b);
		}
	}
	cout << *max_element(arr, arr + 6);
}