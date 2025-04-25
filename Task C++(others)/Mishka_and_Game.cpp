#include <bits/stdc++.h>
using namespace std;



int main() {
	int t, m = 0, c = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;
		if(a > b)
			m++;
		if(a < b)
			c++;
	}
	if(m > c) {
		cout << "Mishka";
	}
	else if(m < c) {
		cout << "Chris";
	}
	else {
		cout << "Friendship is magic!^^";
	}
	
}