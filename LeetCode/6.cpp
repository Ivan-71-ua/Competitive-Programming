#include <bits/stdc++.h>


class Solution {
public:
	std::string convert(std::string s, int numRows) {
		std::vector<std::string> row(numRows);
		//bool full = false;
		int cnt = 0;
		for (int i = 0; i < s.size();)
		{
			if(cnt == numRows) {
				cnt = 0;
				for (int j = numRows - 2; j > 0 && i < s.size(); j--) {
					row[j] += s[i++];
				}
			} else {
				row[cnt++] += s[i++];
			}
		}
		std::string res;
		for (auto &h: row)
		{
			res += h;
		}
		return res;
	}
};


int main() {
	Solution ans;
	ans.convert("PAYPALISHIRING", 3);
}