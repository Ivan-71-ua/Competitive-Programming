#include <bits/stdc++.h>


class Solution {
	int n, m;
	int find(std::string stamp, std::string target) {
		for (int i = 0; i <= m - n; i++)
		{
			int s = 0, t = i;
			bool isAlph = false;
			while(s < n && t < m && (target[t] == '?' || target[t] == stamp[s])) {
				if(target[t] != '?')
					isAlph = true;
				s++, t++;
			}
			if(s == n && isAlph)
				return i;
		}
		return -1;
	}
public:
	std::vector<int> movesToStamp(std::string stamp, std::string target) {
		n = stamp.size();
		m = target.size();
		std::string tmp(m, '?');
		std::vector<int> ans;
		while(tmp != target) {
			int idx = find(stamp, target);
			if(idx < 0) {
				return {};
			} 
			ans.push_back(idx);
			for (int i = idx; i < idx + n; i++)
			{
				target[i] = '?';
			}
		}
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
};