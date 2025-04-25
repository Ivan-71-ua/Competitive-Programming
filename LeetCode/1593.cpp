#include <bits/stdc++.h>


class Solution {
	std::map<std::string, int> subs;
	int max_c = 0;
	void count(std::string st, int idx) {
		if(idx >= st.size())
			max_c = std::max(max_c, (int)subs.size());
		for (int i = idx; i < st.size(); i++)
		{
			std::string tmp = st.substr(idx, i - idx + 1);
			subs[tmp]++;
			count(st, idx + tmp.size());
			subs[tmp]--;
			if(subs[tmp]== 0)
				subs.erase(tmp);
		}
	}
public:
	int maxUniqueSplit(std::string s) {
		count(s, 0);
		return max_c;
	}
};


int main() {
	Solution ans;
	ans.maxUniqueSplit("ababccc");
}