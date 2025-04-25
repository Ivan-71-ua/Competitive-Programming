#include <bits/stdc++.h>
using namespace std;




int main()
{
	set<int> four;
	for (int i = 0; i < 4; i++)
	{
		int c;
		cin >> c;
		four.insert(c);
	}
	cout << 4 - four.size();
}