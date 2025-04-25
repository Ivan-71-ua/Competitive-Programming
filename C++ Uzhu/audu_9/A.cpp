#include <bits/stdc++.h>
using namespace std;

int Quantity_of_number(string str) {
	int k;
	if(str[0] == '-') {
		k = str.size() - 1;
	}
	else {
		k = str.size();
	}
	return k;
}

int main() {
	string n;
	cin >> n;
	cout << Quantity_of_number(n);
}