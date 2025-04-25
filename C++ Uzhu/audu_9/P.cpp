#include <bits/stdc++.h>
using namespace std;

int My_fun(int x, int y, int z) {
	int arr[3] = {z, y, x};
	sort(arr, arr + 3);
	return arr[1];
}

int main() {
	int  x, y, z;
	cin >> x >> y >> z;
	cout << My_fun(x, y, z);
}