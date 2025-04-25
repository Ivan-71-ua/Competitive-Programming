
#include <bits/stdc++.h>



class Solution {
	
	std::vector<char> can{'a', 'b', 'c'};
	std::vector<std::string> comb;
	void Create(int n, int k, std::string st) {
		if(comb.size() >= k)
			return;
		if(st.size() == n) {
			comb.push_back(st);
			return;
		}
		for (int i = 0; i < 3; i++)
		{
			if(st.empty() || (st.back() != can[i])) {
				Create(n, k, st + can[i]);
			}
		}
	}
public:
	std::string getHappyString(int n, int k) {
		Create(n, k, "");
		if(comb.size() < k) {
			return "";
		}
		return comb[k - 1];
	}
};