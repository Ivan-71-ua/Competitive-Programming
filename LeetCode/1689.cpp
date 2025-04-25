#include <bits/stdc++.h>

class Solution {
public:
	int minPartitions(std::string n) {
		return *std::max_element(n.begin(), n.end()) - '0';
	}
};