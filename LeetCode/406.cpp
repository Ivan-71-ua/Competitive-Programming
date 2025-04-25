#include <bits/stdc++.h>





class Solution {
public:
	std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
        std::ios::sync_with_stdio(false);
         std::cin.tie(nullptr);
         std::cout.tie(nullptr);
		std::vector<std::vector<int>> res(people.size());
		std::stable_sort(people.begin(), people.end(), [](const std::vector<int> &a, const std::vector<int> &b)
		{
         if(a[0] == b[0]) {
				return a[1] < b[1];
			} else {
				return a[0] < b[0];
			}
		});
		for (int i = 0; i < people.size(); i++)
		{
			int prev = people[i][1];
			int height = people[i][0];
			for (int j = 0; j < people.size(); j++)
			{
				if(res[j].empty() && prev == 0) {
					res[j] = people[i];
					break;
				} else if(res[j].empty() || res[j][0] >= height)
					prev--;
			}
		}
		return res;
	}
}; 

int main() {
	Solution ans;
	std::vector<std::vector<int>> aa{{7, 0}, { 4, 4 }, { 7, 1 }, { 5, 0 }, { 6, 1 }, {5, 2}};
	ans.reconstructQueue(aa);
}