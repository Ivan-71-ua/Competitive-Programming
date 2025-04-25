#include <bits/stdc++.h>

class Solution {
public:
   int partitionString(std::string s) {
		int an = 0;
		std::string tp;
		for (int i = 0; i < s.size(); i++)
		{
			if(tp.find(s[i]) == -1) {
				tp += s[i];
			} else {
				an++;
				tp = "";
			}
		}
		return an;
	}
};

int main() {
	Solution ans;
	ans.partitionString("abacaba");
}