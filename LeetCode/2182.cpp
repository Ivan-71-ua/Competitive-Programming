#include <bits/stdc++.h>



class Solution { 
public:
	std::string repeatLimitedString(std::string s, int repeatLimit) {
		std::vector<int> alph(26);
		for (auto &ch: s)
		{
			alph[ch - 'a']++;
		}
		std::priority_queue<std::pair<char, int>> q;
		for (int i = 0; i < 26; i++) {
			if(alph[i] > 0) {
				q.push({'a' + i, alph[i]});
			}
		}
		std::string res;
		while(!q.empty()) {
			auto [cur, cnt] = q.top();
			q.pop();
			int use = std::min(cnt, repeatLimit);
			for (int i = 0; i < use; i++)
			{
				res += cur;
			}
			cnt -= use;
			if(cnt > 0) {
				if(!q.empty()) {
					auto [next, n_cnt] = q.top();
					q.pop();
					res += next;
					q.push({cur, cnt});
					if(n_cnt - 1 > 0) {
						q.push({next, n_cnt - 1});
					}
				}	
			}
		}
		return res;
	}
};


int  main() {
	Solution ans;
	ans.repeatLimitedString("cczazcc", 3);
}