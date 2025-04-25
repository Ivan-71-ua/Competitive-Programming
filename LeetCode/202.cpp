#include <bits/stdc++.h>

class Solution {
public:
	bool isHappy(int n) {
		std::unordered_map <int, int> hash;
		int res = n;
		hash[res]++;
		while(true) {
			if(res == 1)
				return true;
			std::string st = std::to_string(res);
			res = 0;
			for (int i = 0; i < st.size(); i++)
			{
				res += ((int)st[i] - 48) * ((int)st[i] - 48);
			}
			if(hash.count(res)) {
				return false;
			}
			hash[res]++;
		}
	}
};


int main() {
	Solution ans;
	ans.isHappy(19);
}