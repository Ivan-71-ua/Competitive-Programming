#include <bits/stdc++.h>


class Solution {
public:
	std::string shortestCommonSupersequence(std::string str1, std::string str2) {
		int size1 = str1.size();
		int size2 = str2.size();
		std::vector<std::string> prev_row(size2 +1);
		for (int i = 0; i <= size2; i++) {
			prev_row[i] = str2.substr(0, i);
		}

		for (int i = 1; i <= size1; i++) {
			std::vector<std::string> cur_row(size2 + 1);
			cur_row[0] = str1.substr(0, i);
			for (int j = 1; j <= size2; j++) {
				if(str1[i -1] == str2[j -1]) {
					cur_row[j] = prev_row[j - 1] + str1[i - 1];
				} else {
					std::string pickS1 = prev_row[j];
					std::string pickS2 = cur_row[j - 1];
					cur_row[j] = (pickS1.size() < pickS2.size())
														? pickS1 + str1[i - 1]
														: pickS2 + str2[j - 1];
				}
			}
			prev_row = cur_row;
		}
		return prev_row[size2];
	}
};


