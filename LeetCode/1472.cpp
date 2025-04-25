#include <bits/stdc++.h>

class BrowserHistory {
	std::vector<std::string> sites;
	int point = 0;
public:
	BrowserHistory(std::string homepage)
	{
		sites.push_back(homepage);
	}
	void visit(std::string url) {
		std::string tmp = sites[point];
		for (; sites.back() != tmp;)
		{
			sites.pop_back();
		}
		sites.push_back(url);
		point++;
	}
	
	std::string back(int steps) {
		point = std::max(0, point - steps);
		return sites[point];
	}
	
	std::string forward(int steps) {
		point = std::min((int)sites.size() - 1, point + steps);
		return sites[point];
	}
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */