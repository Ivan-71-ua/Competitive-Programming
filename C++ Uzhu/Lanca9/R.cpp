#include <bits/stdc++.h>
using namespace std;


void str() {
	int n;
	string s;
	cin >> n;
	getline(cin, s);
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if(isdigit(s[i])) {
				k++;
			}
		}
		cout << k << endl;
		}
}

int main() {
	str();
}