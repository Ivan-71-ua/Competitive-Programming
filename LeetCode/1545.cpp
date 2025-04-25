#include <bits/stdc++.h>




class Solution {
	void invers(std::string &st) {
		for (auto &ch: st)
		{
			ch = '0' + (1 - (ch - '0'));
		}
	}
	void reverses(std::string &st) {
		std::reverse(st.begin(), st.end());
	}
	std::string findKth(int n) {
		if(n == 1)
			return "0";
		std::string fr = findKth(n - 1);
		std::string sc = fr;
		invers(sc);
		reverses(sc);
		return fr + "1" + sc;	
	}
public:
	char findKthBit(int n, int k) {
		std::string res = findKth(n);
		return res[k - 1];
	}
};