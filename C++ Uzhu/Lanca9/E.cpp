#include <bits/stdc++.h>
using namespace std;



void simple ( long long a){
	if((a & (a - 1)) == 0) {
		int k = 0;
		while (a != 1) {
			a = a >> 1;
			k++;
		}
		for (int i = 0; i < k; i++)
		{
			cout << 2;
			if(i != k -1) {
				cout << "*";
			}
		}
		
		
	}
	else {
		for (int i = 2; i <= a;)
		{
			if(a % i == 0) {
				cout << i;
				a /= i;
				if(a == 1) {
					break;
				}
				else {
					cout << "*";
				}
			}
			else {
				i++;
			}
		}
		}
	
	
}

int main() {
	long long n;
	cin >> n;
	simple(n);
}