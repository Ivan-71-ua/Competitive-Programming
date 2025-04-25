#include <bits/stdc++.h>
using namespace std;

int main() {
	string a;
	cin >> a;
	int c = a.length();
	if (a[c - 1] == '5') {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	if (a[c - 1] == '0') {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}