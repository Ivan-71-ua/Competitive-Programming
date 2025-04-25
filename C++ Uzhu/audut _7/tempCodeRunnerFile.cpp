#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	char b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a;
		cin >> a;
		b ^= a;
	}
	if(!b) {
		cout << "Ok";
	}
	else {
		cout <<  b;
	}
}