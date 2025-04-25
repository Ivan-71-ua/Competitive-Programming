#include <bits/stdc++.h>
using namespace std;




int main()
{
	int a, b, c, e, d;
	cin >> a >> b >> c >> e >> d;
	set<int> kik;
	if(a == 1) {
		cout << d;
	}
	else {
		for (int i = a; i <= d ; i+= a)
		{
			kik.insert(i);
		}
		for (int i = b; i <= d ; i+= b)
		{
			kik.insert(i);
		}
		for (int i = c; i <= d ; i+= c)
		{
			kik.insert(i);
		}
		for (int i = e; i <= d ; i+= e)
		{
			kik.insert(i);
		}
		cout << kik.size();
	}
}

