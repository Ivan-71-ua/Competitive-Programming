#include <bits/stdc++.h>

class Solution {
public:
   int minOperations(std::string s) {
		int ans = 0, ans2 = 0;
		std::string ss = s;
		for (int i = 0; i < ss.size() -1; i++)
		{
			if(ss[0] == '1')
				ans++;
			ss[0] = '0';
			if(ss[i] == ss[i +1]
			) {
				ans++;
				if(ss[i] == '0')
					ss[i + 1] = '1';
				if(ss[i] == '1')
					ss[i + 1] = '0';
			}
		}
		ss = s;
		for (int i = 0; i < ss.size() - 1; i++)
		{
			if(ss[0] == '0')
				ans2++;
			ss[0] = '1';
			if(ss[i] == ss[i +1]) {
				ans2++;
				if(ss[i] == '0')
					ss[i + 1] = '1';
				if(ss[i] == '1')
					ss[i + 1] = '0';
			}
		}
		return std::min(ans, ans2);
	}
};

int main() {
	Solution ans;
	ans.minOperations("10010100");
}