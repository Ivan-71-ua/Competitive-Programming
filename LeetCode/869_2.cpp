
#include <bits/stdc++.h>

class Solution {
public:
	bool reorderedPowerOf2(int n) {
		if((n & (n -1)) == 0)
			return true;
		std::vector<int8_t> dig;
		while(n){
			dig.push_back(n % 10);
			n /= 10;
		}
      sort(dig.begin(), dig.end());
		do {
			if(dig[0] != 0) {
				int cur = 0;
				for (int i = 0; i < dig.size(); i++) {
					cur *= 10;
					cur += dig[i];
				}
				if((cur & (cur -1)) == 0)
					return true;
			}
		} while(std::next_permutation(dig.begin(), dig.end()));
		return false;
	}
};