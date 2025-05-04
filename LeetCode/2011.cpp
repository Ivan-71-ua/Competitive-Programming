#include <bits/stdc++.h>



class Solution {
public:
	int finalValueAfterOperations(std::vector<std::string>& operations) {
		int res = 0;
		for(auto i: operations) {
			if(i[1] == '+') {
				res++;
			} else {
				res--;
			}
		}
		return res;
	}
};