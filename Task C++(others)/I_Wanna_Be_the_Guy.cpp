#include <bits/stdc++.h>
using namespace std;




int main()
{
	int n;
	cin >> n;
	set<int> level;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int c;
		cin >> c;
		level.insert(c);
	}
	int k1;
	cin >> k1;
	for (int i = 0; i < k1; i++)
	{
		int c;
		cin >> c;
		level.insert(c);
	}

	if(level.size() == n) {
		cout << "I become the guy.";
	}
	else {
		cout << "Oh, my keyboard!";
	}
}