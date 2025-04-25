#include <bits/stdc++.h>
using namespace std;

int Quantity_of_number(string str) {
	int k = 0;
	if(str[0] == '-') {
		for (int i = 1; i < str.size(); i++)
		{
			k += (int)str[i] - 48;
		}
		
	}
	else {
		for (int i = 0; i < str.size(); i++)
		{
			k += (int)str[i] - 48;
		}
	}
	return k;
}

int main() {
	string n;
	cin >> n;
	cout << Quantity_of_number(n);
}