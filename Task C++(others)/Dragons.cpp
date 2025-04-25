#include <bits/stdc++.h>
using namespace std;


int main() {
	multimap<int, int> drag;
	int s, n;
	cin >> s >> n;
	for (int i = 0; i < n; i++)
	{
		int c, b;
		cin >> c >> b;
		drag.insert( pair<int,int>(c,b) );;
	}
	bool an = true;	
	for (auto now : drag)
	{
		if(s > now.first) {
			s += now.second;
		}
		else {
			an = false;
			break;
		}
	}
	if(an) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
}