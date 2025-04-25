#include <bits/stdc++.h>


class Solution {
public:
	std::string countOfAtoms(std::string formula) {
		std::map<std::string, int> atoms;
		std::vector<std::pair<std::string, int>> elem;
		std::string fr;
		for (int i = 0; i < formula.size(); i++) 
		{
			if(isalpha(formula[i])) {
				int j = i;
				while('a' <= formula[i + 1] && formula[i + 1] <= 'z') {
					//fr += " " + formula.substr(i, 2) + " ";
					i++;
				} 
				fr += " ";
				fr += formula.substr(j, i - j + 1);
				fr += " ";
			} else if(isdigit(formula[i])) {
				fr += formula[i];
			} else {
				fr += " ";
				fr += formula[i];
				fr += " ";
			}
		}
		std::stringstream parse(fr);
		std::vector<std::string> to_do;
		while(parse >> fr) {
			to_do.push_back(fr);
		}
		for (int i = 0; i < to_do.size(); i++)
		{
			if(to_do[i] == ")") {
				std::vector<std::pair<std::string, int>> tmp;
				int mult = 1;
				if(i + 1 < to_do.size() &&  isdigit(to_do[i +1][0])) {
					i++;
					mult *= std::stoi(to_do[i]);
				}
				while(true) {
					auto [a, c] = elem.back();
					elem.pop_back();
					if(a == "(") break;
					tmp.push_back({a, c * mult});
				}
				while(tmp.size()) {
					elem.push_back(tmp.back());
					tmp.pop_back();
				}
			} else if(to_do[i] == "(") {
				elem.push_back({to_do[i], 0});
			} else if(isalpha(to_do[i][0])) {
				elem.push_back({to_do[i], 1});
			} else {
				elem.back().second *= std::stoi(to_do[i]);
			}
		}
		for (auto &&n : elem)
		{
			atoms[n.first] += n.second;
		}
		std::string res;
		for (auto &&now : atoms)
		{
			res += now.first;
			if(now.second > 1) {
				res += std::to_string(now.second);
			}
		}
		return res;
	}
};


int main() {
	Solution ans;
	ans.countOfAtoms("H2O");
}