#include <bits/stdc++.h>

class Solution {
public:
   bool isUgly(int n) {
      if(n == 1)
			return 1;
		if(n <= 0)
			return 0;
		while(n % 2 == 0)
			n /= 2;
		while(n % 3 == 0)
			n /= 3;
		while(n %5 == 0)
			n /= 5;
		return n == 1;
	}
};