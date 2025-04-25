#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;


long long f (long long a, long long n) {
   if (!n)
      return 1;
   if (n & 1)
      return (f (a, n - 1) * a);
   return f ((a * a), n/2);
}




void HROZNY(){
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		for (int i = 2; i <=29; i++)
		{
			if(n % (f(2, i)-1 ) == 0) {
				std::cout << n / (f(2, i)-1 ) << '\n';
				break;
			}
		}
	}
}

int main() {
	HROZNY();
}