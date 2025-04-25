#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int a, b;
	cin >> a >> b;
	cout << b - a + 2 << endl;
	for (int i = a , l = b - a; l >= 1;i++, l--)
	{
		cout << s.substr(i, l) << endl;
	}
	
}