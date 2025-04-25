#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int k;
		cin >> k;
		if(k <= 1399)  {
			cout << "Division 4\n";
		}
		else if(1400 <= k && k <= 1599) {
			cout << "Division 3\n";
		}
		else if(1600 <= k  && k <= 1899) {
			cout << "Division 2\n";
		}
		else if(1900 <= k)  {
			cout << "Division 1\n";
		}
	}
}