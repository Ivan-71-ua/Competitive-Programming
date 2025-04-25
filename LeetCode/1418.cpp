#include <bits/stdc++.h>


	class Solution {
	public:
		std::vector<std::vector<std::string>> displayTable(std::vector<std::vector<std::string>>& orders) {
			std::set<std::string> name;
			std::map<int, std::map<std::string, int>> table_dish_count;
			for (auto now: orders)
			{
				name.insert(now[2]);
				table_dish_count[stoi(now[1])][now[2]]++;
			}
			std::vector<std::vector<std::string>> ans;
			std::vector<std::string> first_row;
			first_row.push_back("Table");
			for (auto now : name)
			{
				first_row.push_back(now);
			}
			ans.push_back(first_row);
			for (auto now: table_dish_count)
			{
				std::vector<std::string> row;
				row.push_back(std::to_string(now.first));
				for (int j = 1; j < ans[0].size(); j++)
				{
					row.push_back(std::to_string(now.second[ans[0][j]]));
				}
				ans.push_back(row);
			}
			return ans;
		}
	};