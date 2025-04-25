#include <bits/stdc++.h>


class Solution {
public:
std::vector<std::string> subdomainVisits(std::vector<std::string>& cpdomains) {
	std::vector<std::string> ans;
	std::unordered_map<std::string, int> count;
	for (const std::string& cpdomain : cpdomains) {
	const int space = cpdomain.find(' ');
	const int num = stoi(cpdomain.substr(0, space));
	const std::string& domain = cpdomain.substr(space + 1);
	count[domain] += num;
	for (int i = 0; i < domain.length(); ++i)
		if (domain[i] == '.')
			count[domain.substr(i + 1)] += num;
	}
	for (const auto& [subdomain, freq] : count)
	ans.push_back(std::to_string(freq) + ' ' + subdomain);
	return ans;
	}
};