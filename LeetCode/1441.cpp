#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::string> buildArray(std::vector<int>& target, int n) {
		int i = 0;
		int intiger = 1;
		std::vector<std::string> res;
		while(i < target.size()) {
			if(target[i] == intiger) {
				res.push_back("Push");
				i++;
			} else {
				res.push_back("Push");
				res.push_back("Pop");
			}
			intiger++;
		}
		return res;
	}
};