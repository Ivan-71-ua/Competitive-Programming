#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		string k = "0";
		k = k + s[i];
		sum += stoi(k);
	}
	if(sum % 3 == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}