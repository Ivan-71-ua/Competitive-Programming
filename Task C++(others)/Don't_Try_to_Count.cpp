#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m, k, temp = 0;
		bool ans = false;
		string x, y;
		cin >> m >> k;
		cin >> x >> y;
		int j = 0;
		while(j < 10) {
			if(x.find(y) != string::npos) {
				ans = true;
				cout << temp << endl;
				break;
				
			}
			else{
				x = x + x;
				temp++;
				j++;
			}
			
		}
		if(ans == false) {
			cout << -1 << endl;
		}
		
	}
	
}