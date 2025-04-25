#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int k = 0, k1 = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == '2') {
			k++;
		}
		else {
			k1++;
		}
	}
	if(k > k1) {
		cout << 2;
	}
	else if(k < k1) {
		cout << 5;
	}
	else {
		cout << '=';
	}

}