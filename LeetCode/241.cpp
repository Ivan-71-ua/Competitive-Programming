#include <bits/stdc++.h>


class Solution {
	std::vector<int> get_all(int l, int r, std::string exp) {
		std::vector<int> res;
		for (int i = l; i < r; i++)
		{
			if(!isdigit(exp[i])) {
				std::vector<int> num1 = get_all(l, i - 1, exp);
				std::vector<int> num2 = get_all(i + 1, r, exp);
				for (auto n1 : num1)
				{
					for (auto n2 : num2)
					{
						if(exp[i] == '*') {
							res.push_back(n1 * n2);
						}else if(exp[i] == '+') {
							res.push_back(n1 + n2);
						} else {
							res.push_back(n1 - n2);
						}
					}  
				}
			}
		}
		if(res.empty()) {
			res.push_back(std::stoi(exp.substr(l, r - l + 1)));
		}
		return res;
	}
public:
	std::vector<int> diffWaysToCompute(std::string expression) {
		return get_all(0, expression.size(), expression);
	}
};