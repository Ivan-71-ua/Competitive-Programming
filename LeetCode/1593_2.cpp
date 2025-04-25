
#include <bits/stdc++.h>



class Solution {
	std::set<std::string> subs;
	int max_c = 0;
	
	void count(const std::string& st, int idx) {
		if (idx >= st.size()) {
			max_c = std::max(max_c, (int)subs.size());
			return;
		}
		
		for (int i = idx; i < st.size(); i++) {
			std::string tmp = st.substr(idx, i - idx + 1);
			
			if (subs.find(tmp) == subs.end()) {
				subs.insert(tmp);
				count(st, i + 1);
				subs.erase(tmp);  
			}
		}
	}
	
public:
	int maxUniqueSplit(std::string s) {
		count(s, 0);
		return max_c;
	}
};
