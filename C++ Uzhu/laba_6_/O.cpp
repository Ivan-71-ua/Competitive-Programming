#include <bits/stdc++.h>
using namespace std;


int main() {
	int min = 1001;
	for (int i = 0; i < 3; i++)
	{
		int n;
		cin >> n;
		if(n < min) {
			min = n;
		}
	}
	cout << min;
}