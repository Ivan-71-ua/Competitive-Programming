#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p = 1, k;
	cin >> n;
	k = n;
	while(n >= (p << 1)) {
		p = p << 1;
	}
	int p1 = p--;
	for (int i = 0; i < k; i++)
	{
		if((n & p) == p) {
			n = ((n << 1) & p1) ^ 1;
		}
		else {
			n = ((n << 1) & p1);
		}
	}
	int p = 1, k= 0;
	
}