#include <bits/stdc++.h>

class Solution {
public:
   int minOperations(std::string s) {
		int count = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if(i % 2 == 0) {
				if(s[i] == '0')
					count++;
			} else {
				if(s[i] == '1')
					count++;
			}
		}
		return std::min(count, (int)s.size() - count);
	}
};

int main() {
	Solution ans;
	ans.minOperations("10010100");
}