#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> findingUsersActiveMinutes(std::vector<std::vector<int>>& logs, int k) {
		std::map	<int, std::set<int>> users;
		for (int i = 0; i < logs.size(); i++)
		{
			users[logs[i][0]].insert(logs[i][1]);
		}
		std::vector<int> res(k);
		for (auto &&now : users)
		{
			res[now.second.size() -1]++;
		}
		return res;
	}
};