#include <bits/stdc++.h>
using namespace std;


int main() {
   int n, k;
	cin >> n >> k;
   int x = 1; 
   while ((x<<1) <= k){
      x = x<<1;
   }
	int h = 0;
	int ans = 0;
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		int p, y;
		y = x;
		y = (y >> h) ^ (1 << h);
 		p = k & y;
		p = p >> h;
		if(p == 1) {
			p = p << (n - h - 1);
			
		}
		else if (!(p &(p -1))) {
			p = p >> (n - h -1);
	
		}
		ans = ans ^ (p);
		h++;
	}
	cout << ans;
}

