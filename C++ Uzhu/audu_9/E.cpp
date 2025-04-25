#include <bits/stdc++.h>
using namespace std;

double Square(string str) {
	double k = 0;
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
	return sqrt(k);
}

int main() {
	string n;
	cin >> n;
	cout << fixed << setprecision(3);
	cout << Square(n);
}