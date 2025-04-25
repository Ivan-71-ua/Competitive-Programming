#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int crime = 0, polismen = 0;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		if(c == -1) {
			if(polismen + c < 0) {
				crime += abs(c);
			}
			else{
				polismen = polismen + c;
			}
		}
		else {
			polismen += c;
		}
	}
	cout << crime;	
}