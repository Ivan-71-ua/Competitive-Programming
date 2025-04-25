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
		if(s.find("BSM") != string::npos) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		
	}
}

int main() {
	str();
}