#include <bits/stdc++.h>

class Solution {
public:
   int fib(int n) {
		if(n == 0)
			return 0;
		if(n == 1)
			return 1;
		int arr_f[n + 1];
		arr_f[0] = 0;
		arr_f[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			arr_f[i] = arr_f[i - 1] + arr_f[i - 2];
		}
		return arr_f[n];
	}
};