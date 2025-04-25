#include <bits/stdc++.h>

/*
1+2+3+...+x = n
-> (1+x)x/2 = n
-> x^2+x = 2n
-> x^2+x+1/4 = 2n +1/ 4
-> (x+1/2)^2 = 2n +1/4
-> (x+0,5) = sqrt(2n+0,25)
-> x = -0,5 + sqrt(2n+0,25)
*/


class Solution {
public:
	unsigned int arrangeCoins(int n) {
		return (unsigned int)(-0.5 + sqrt(2 * (long long)n + 0.25));
	}
};
