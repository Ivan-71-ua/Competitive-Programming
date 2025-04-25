#include <bits/stdc++.h>
using namespace std;


int main() {
	int a, b;
	char ch;
	cin >> a >> ch >> b;
	if(ch == '+') {
		cout << a + b;
	}
	if(ch == '-') {
		cout << a - b;
	}
	if(ch == '/') {
		cout << a / b;
	}
	if(ch == '*') {
		cout << a * b;
	}
}