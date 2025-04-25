#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[1000] {};
	int k = 0;
	int n = 1;
	while(k != 1000) {
		int l = n % 10;
		if(n % 3 == 0 && l == 3 || n % 3 == 0 || l == 3) {
			
			n++;
		}
		else {
			arr[k] = n;
			k++;
			n++;
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int h;
		cin >> h;
		cout << arr[h -1];
		cout << endl;
	}
	
}