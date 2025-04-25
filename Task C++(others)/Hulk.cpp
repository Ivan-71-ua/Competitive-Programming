#include <bits/stdc++.h>
using namespace std;




int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s = "I hate";
		string s1 = " that ";
		string s2 = "I love";
		if(i == 1) {
			cout << s;
		}
		else {
			if(i % 2 == 0) {
				cout << s1 + s2;
			}
			else {
				cout << s1 + s;
			}
		}
	}
	cout << " it";
}