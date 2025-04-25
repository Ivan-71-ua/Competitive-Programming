#include <bits/stdc++.h>



class Solution {
	
public:
	std::string longestDiverseString(int a, int b, int c) {
		std::string res;
		std::priority_queue<std::pair<int, char>> q;
		if(a > 0) {
			q.push({a, 'a'});
		}
		if(b > 0) {
			q.push({b, 'b'});
		}
		if(c > 0) {
			q.push({c, 'c'});
		}

		while(!q.empty()) {
			auto [cnt, ch] = q.top();
			q.pop();
			if(res.size() >= 2 && res.back() == ch && res[res.size() -2] == ch) {
				if(q.empty()) break;
				auto [cnt2, ch2] = q.top();
				q.pop();
				cnt2--;
				res += ch2;
				if(cnt2)
					q.push({cnt2, ch2});
				q.push({cnt, ch});	
			} else {
				cnt--;
				res += ch;
				if(cnt)
					q.push({cnt, ch});
			}
		}
		return res;
	}
};