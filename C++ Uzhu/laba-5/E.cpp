#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k;
	int g = 0; 
	cin >> n >> k;
	for (int i = 0; i < n * k;i++) {
		int c;
		cin >> c;
		if(c % 2 == 0) {
			g++;
		}
	}
	cout << g;
}