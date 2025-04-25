#include <bits/stdc++.h>





class Solution {
public:
	int minFlips(int a, int b, int c) {
		int r = 0;
		int res = 0;
		while(r < 32) {
			long long cur = 1 << r;
			if(c & cur) {
				if((a & cur) + (cur & b) == 0)
					res++;
			} else {
				if(a & cur)
					res++;
				if(cur & b)
					res++;
			}
			r++;
		}
		return res;
	}
};


int main() {
	Solution ans;
	ans.minFlips(2, 6, 5);
}