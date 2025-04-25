#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	getline(cin, s);
	int b = 0, c = 0, k = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] <= 90 && s[i] >= 65) {
			b++;
		}
		else {
			c++;
		}
	}
	if(b >= s.size() - 1 || c >= s.size() - 1) {
		cout << "YES" << " " << s.size() << endl;
	}
	else {
		int m = min(s.size() - b, s.size() - c);
		cout << "NO " << m << endl;
	}
}