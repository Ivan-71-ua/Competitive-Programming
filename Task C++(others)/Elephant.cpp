#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k = 0, x = 5;
	cin >> n;
	while(n != 0) {
		if(n - x >= 0) {
			n = n - x;
			k++;
		}
		else {
			x--;
		}
	}
	cout <<  k;
}