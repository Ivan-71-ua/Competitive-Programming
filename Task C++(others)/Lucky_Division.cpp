#include <bits/stdc++.h>
using namespace std;




int main()
{
	string n;
	cin >> n;
	if(n.find("0") != string::npos || n.find("1") != string::npos || n.find("2") != string::npos || n.find("3") != string::npos || n.find("5") != string::npos ||n.find("6") != string::npos || n.find("8") != string::npos || n.find("9") != string::npos)
	{
		int n1 = stoi(n);
		if(n1 % 4 == 0 || n1 % 7 == 0 || n1 % 47 == 0 || n1 % 74 == 0 || n1 % 44 == 0 || n1 % 77 == 0) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	else {
		cout << "YES";
	}
}