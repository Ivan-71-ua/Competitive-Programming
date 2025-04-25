#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int arr[3]{a, b, c};
		sort(arr, arr + 3);
		if(arr[0] + arr[1] == arr[2]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
}