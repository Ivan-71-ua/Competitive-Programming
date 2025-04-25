#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		if(c / 2 <= 0) {
			cout << 0 << endl;
		}
		else if(!(c & 1)) {
			cout << c / 2 - 1 << endl;
		}
		else {
			cout << c / 2 << endl;
		}
	}
	
}