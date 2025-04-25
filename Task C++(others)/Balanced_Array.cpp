#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		if(n % 4 != 0) {
			cout << "NO\n";
		}
		else {
			int arr[n];
			int sum = 0, sum1 = 0;
			for (int i = 0, l = 2; i < n / 2; i++, l+=2) {
				arr[i] = l;
				sum += l;
			}
			for (int i = n / 2, l = 1; i < n - 1; i++, l+=2) {
				arr[i] = l;
				sum1 += l;
			}
			arr[n - 1] = sum - sum1;
			cout << "YES\n";
			for(auto now: arr) {
				cout << now << ' ';
			}
			cout << endl;
		}
	}
	
}