#include <bits/stdc++.h>



class Solution {
public:
	long long numberOfPowerfulInt(long long start, long long finish, int limit, std::string s) {
		std::string st = std::to_string(start -1);
		std::string fi = std::to_string(finish);
		return calcut(fi, s, limit) - calcut(st, s, limit);
	}
	long long calcut(std::string num, std::string suf, int lim) {
		if(num.size() < suf.size()) {
			return 0;
		}
		if(num.size() == suf.size()) {
			return num >= suf ? 1 : 0;
		}
		std::string str_suffix = num.substr(num.size() - suf.size(), suf.size());
		long long cnt = 0;
		int pref_len = num.size() - suf.size();
		for (int i = 0; i < pref_len; i++) {
			if(lim < (num[i] - '0')) {
				cnt += (long long)pow(lim + 1, pref_len - i);
				return cnt; 
			}
			cnt += (long long)pow(lim + 1, pref_len - i - 1) * (num[i] - '0');
		}
		if(str_suffix >= suf) {
			cnt++;
		}
		return cnt;
	}
};