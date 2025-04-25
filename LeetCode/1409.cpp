#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> processQueries(std::vector<int>& queries, int m) {
		std::list<int> permut;
		std::vector<int> ans;
		for (int i = 1; i <= m; i++)
		{
			permut.push_back(i);
		}
		for (int i = 0; i < queries.size(); i++)
		{
			int id = 0;
			for (auto it = permut.begin(); it != permut.end(); it++)
			{
				if(*it == queries[i]) {
					int tmp = *it;
					ans.push_back(id);
					permut.erase(it);
					permut.push_front(tmp);
					break;
				}
				id++;
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{3, 1, 2, 1};
	ans.processQueries(ss, 5);
}