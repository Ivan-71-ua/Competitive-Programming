#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string c;
		cin >> c;
		if(c.size() == 1) {
			cout << c.size() << endl;
			cout << c << endl;
		}
		else {
			int k = 0;
			for (int i = 0; i < c.size(); i++)
			{
				if(c[i] != '0') {
					k++;
				}
			}
				cout << k << endl;
				int step = 1;
				int num = stoi(c);
				while (num != 0)
				{
					int p = num % 10;
					num /= 10;	
					p *= step;
					step *= 10;
					if(p != 0) {
						cout << p << " ";
					}
				}
				cout << endl;
				}
	}
	
}