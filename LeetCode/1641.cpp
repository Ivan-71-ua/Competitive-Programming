#include <bits/stdc++.h>

class Solution {
public:
   int countVowelStrings(int n) {
		return count(n, 5);
	}
	int count(int n, int k) {
		if(n == 1)
			return k;
		if(k == 1)
			return 1;
		return count(n - 1, k) + count(n, k - 1);
	}
};