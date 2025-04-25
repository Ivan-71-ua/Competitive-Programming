#include <bits/stdc++.h>

class Solution {
	
public:
	std::string convertToTitle(int columnNumber) {
		std::string res = "";
		while(columnNumber > 0) {
			int tp = (columnNumber - 1) % 26;
			res += 'A' + tp;
			columnNumber = (columnNumber -1) / 26;
		}
		std::reverse(res.begin(), res.end());
		return res;
	}
};

int main() {
	Solution ans;
	ans.convertToTitle(701);
}