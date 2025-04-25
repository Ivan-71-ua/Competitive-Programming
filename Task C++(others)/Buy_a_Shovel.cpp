#include <bits/stdc++.h>
using namespace std;


int main() {
	int k, n;
	cin >> k >> n;
	for (int i = 1; i <= 10; i++)
	{
		if((k * i) % 10 == 0 || (k * i) % 10 == n) {
			cout << i;
			break;
		}
	}
	
}