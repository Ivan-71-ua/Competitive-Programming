#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::string> subdomainVisits(std::vector<std::string>& cpdomains) {
		std::unordered_map<std::string, int> visit_domen;
		for (auto now: cpdomains)
		{
			std::stringstream parse(now);
			int visit;
			std::string domen;
			parse >> visit;
			parse >> domen;
			int i = domen.size() -1;
			std::string sub_domen = "";
			while(i > -1) {
				if(domen[i] == '.') {
					visit_domen[sub_domen] += visit;
				}
				sub_domen.insert(0, 1, domen[i]);
				if(i == 0) {
					visit_domen[sub_domen] += visit;
				}
				i--;
			}
		}
		std::vector<std::string> res;
		for (auto now: visit_domen)
		{
			res.push_back(std::to_string(now.second) + ' ' + now.first);
		}
		return res;
	}
};