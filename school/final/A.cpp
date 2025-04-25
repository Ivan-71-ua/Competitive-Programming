#include <bits/stdc++.h>
using namespace std;

bool is_sp (int a) {
	if(a == 1)
		return false;
	if(a == 2)
		return true;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if(a % i != 0)
			return 0;
	}
	return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a, b, count =0;
    cin >> a >> b;
    while(a != 0 && b != 0) {
        long long ds = gcd(a, b);
		  if(a % ds == 0 && b % ds == 0) {
			  count++;
			  a /= ds;
			  b /= ds;
		  }
		  else if(is_sp(a) && is_sp(b)) {
			count += min(a, b);
			  break;
		  }
			  
		  else  {
			a -= ds;
         b-= ds;
         count++;
		  }
		  
    }
    cout << count;
}