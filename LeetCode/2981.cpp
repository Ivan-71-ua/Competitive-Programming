#include <bits/stdc++.h>


class Solution {
	std::vector<int> pref_fun(std::string s) {
		int n = s.size();
		std::vector<int> pref(n);
		for (int i = 1; i < n; i++) {
			int j = pref[i -1];
			while(s[i] != s[j] && j > 0) {
				j = pref[j -1];
			}
			if(s[i] == s[j]) j++;
			pref[i] = j;
		}
		return  pref;
	}
public:
	int maximumLength(std::string str) {
		int ans = -1;
		int n = str.size();
		for (int s = 0; s < n; s++)
		{
			for (int f = s; f < n; f++)
			{
				int size = f - s + 1;
				bool skip = false;
				std::string sub = str.substr(s, size);
				for (int i = 1; i < size; i++)
				{
					if(sub[i -1] != sub[i]) {
						skip = true;
						break;
					}
				}
				if(skip) continue;
				sub += "#" + str;
				std::vector<int> pref = pref_fun(sub);
				int cur_q = 0;
				for (auto &j : pref)
				{
					if(j == size)
						cur_q++;
				}
				if(cur_q > 2)
					ans = std::max(ans, size);
			}
		}
		return ans;
	}
};

int main() {
	std::string a = "aa#aaaa";
	Solution ans;
	
	
}