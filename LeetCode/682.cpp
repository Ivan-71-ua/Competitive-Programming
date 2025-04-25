#include <bits/stdc++.h>


class Solution {
public:
	int calPoints(std::vector<std::string>& operations) {
		std::stack<int> way;
		for (int i = 0; i < operations.size(); i++)
		{
			if(operations[i] ==  "C") {
				way.pop();
			}else if(operations[i] == "D" ) {
				way.push(way.top() * 2);
			} else if(operations[i] == "+") {
				int f = way.top();
				way.pop();
				int s = way.top();
				way.push(f);
				way.push(f + s);
			} else {
				way.push(std::stoi(operations[i]));
			}
		}
		int res = 0;
		while(!way.empty()) {
			res += way.top();
			way.pop();
		}
		return res;
	}
};