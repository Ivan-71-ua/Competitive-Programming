#include <bits/stdc++.h>



class Solution {
public:
	int maximum69Number (int num) {
		std::string sn = std::to_string(num);
		for(int i = 0; i < sn.size(); i++) {
			if(sn[i] == '6') {
					sn[i] = '9';
					break;
			}
		}
		return std::stoi(sn);
	}
};