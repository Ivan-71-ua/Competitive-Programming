#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int a, b;
	cin >> a >> b;
	string k = s.substr(a - 1, b - a + 1);
	cout << b - a + 1 << endl;
	cout << k;
}