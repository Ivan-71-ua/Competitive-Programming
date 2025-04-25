#include <bits/stdc++.h>

class Solution {
public:
	bool parseBoolExpr(std::string exp) {
		std::stack<char> does;
		std::vector<std::vector<char>> values;
		for (int i = 0; i < exp.size(); i++)
		{
			if(exp[i] == '!' || exp[i] == '|' || exp[i] == '&') {
				does.push(exp[i]);
			} else if(exp[i] == '(') {
				values.push_back({});
			} else if(exp[i] == ')') {
				bool status = values.back().back() == 'f' ? false : true;
				char wh = does.top();
				does.pop();
				values.back().pop_back();
				if(wh == '!') {
					status = !status;
				}
				while (values.back().size())
				{
					if(wh == '|') {
						status = status | (values.back().back() == 'f' ? false : true);
						values.back().pop_back();
					} else {
						status = status & (values.back().back() == 'f' ? false : true);
						values.back().pop_back();
					}
				} 
				values.pop_back();
				if(!values.size())
					values.push_back({});
				values.back().push_back(status ? 't' : 'f');
			} else if(exp[i] != ',') {
				values.back().push_back(exp[i]);
			}
		}
		return values.back().back() == 'f' ? false : true;
	}
};


int main() {
	Solution ans;
	ans.parseBoolExpr("!(&(f,t))");
}