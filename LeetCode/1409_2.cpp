#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> processQueries(std::vector<int>& queries, int m) {
		std::vector<int> permut;
		std::vector<int> ans;
		for (int i = 1; i <= m; i++)
		{
			permut.push_back(i);
		}
		for (auto now: queries)
		{
			auto id = std::find(permut.begin(), permut.end(), now);
			ans.push_back(id - permut.begin());
			permut.erase(id);
			permut.insert(permut.begin(), now);
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{3, 1, 2, 1};
	ans.processQueries(ss, 5);
}