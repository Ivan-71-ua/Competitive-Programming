#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
		std::sort(folder.begin(), folder.end());
		std::vector<std::string> res;
		res.push_back(folder[0]);
		for (int i = 1; i < folder.size(); i++) {
			std::string start = res.back();
			start += "/";
			if(folder[i].compare(0, start.size(), start) != 0) {
				res.push_back(folder[i]);
			}
		}
		return res;
	}
};