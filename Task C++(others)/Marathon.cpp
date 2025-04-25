#include <bits/stdc++.h>
using namespace std;



int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int k = 0;
		if(a < b)
			k++;
		if(a < c)
			k++;
		if(a < d)
			k++;
		cout << k << endl;
	}
	
}