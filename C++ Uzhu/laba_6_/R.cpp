#include <bits/stdc++.h>
using namespace std;


int main() {
	int n = 4, max = -1001;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(max < a) {
			max = a;
		}
	}
	cout << max;
}