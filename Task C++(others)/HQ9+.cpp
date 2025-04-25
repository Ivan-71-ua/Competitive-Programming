#include <bits/stdc++.h>
using namespace std;




int main()
{
	string s;
	cin >> s;
	int k = s.length();
	bool cuan = true;
	for (int i = 0; i < k; i++)
	{
		if(s[i] == 'H'|| s[i] == 'Q' || s[i] == '9') {
			cuan = false;
		}
	}
	if(cuan) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
}