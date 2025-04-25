#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(!(i & 1)) {
				cout << "#";
			}
			else if((i & 1) && (!(k & 1)) && j == m - 1) {
				cout << "#";
			}
			else if((i & 1) && k & 1 && j == 0) {
				cout << "#";
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
		if(i & 1) {
			k++;
		}
	}
	
}