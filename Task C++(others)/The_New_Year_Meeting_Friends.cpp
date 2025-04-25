#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, x1, x2;
	cin >> x >> x1 >> x2;
	int arr[3]{x, x1, x2};
	sort(arr, arr + 3);
	cout << (arr[1] - arr[0]) + (arr[2] - arr[1]);
} 	