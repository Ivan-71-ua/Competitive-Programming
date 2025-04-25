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
		int l = stoi(k);
		if(l % 2 == 0) {
			sum += l;
		}
	}
	cout << sum;
}