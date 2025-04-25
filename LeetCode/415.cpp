#include <bits/stdc++.h>

class Solution {
public:
	std::string addStrings(std::string num1, std::string num2) {
		std::string st;
		st.reserve(std::max(num1.size(), num2.size()) + 1);
		int i = num1.size() - 1;
		int j = num2.size() - 1;
		int add = 0;
		while(i >= 0 ||  j >= 0 || add > 0) {
			if(i >= 0) {
				add += num1[i] - '0';
				i--;
			}
			if(j >= 0) {
				add += num2[j] - '0';
				j--;
			}
			st.push_back((char)(add % 10 + '0'));
			add /= 10;
		}
		assert(i < 0 && j < 0 && add == 0);	
		std::reverse(begin(st), end(st));
		assert(st.size() == 1 || (st.size() > 1 && st[0] != '0'));
		return st;
	}
};

int main() {
	Solution ans;
	ans.addStrings("456", "77");
}