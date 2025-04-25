#include <bits/stdc++.h>

class Solution {
public:
   int leastBricks(std::vector<std::vector<int>>& wall) {
		bool ans = false;
		for (int i = 0; i < wall.size(); i++)
		{
			if(wall[i].size() > 1)
				ans = true;
		}
		if(ans) {
			std::unordered_map<int, int> sum_quant;
			for (int i = 0; i < wall.size(); i++)
			{
				int sum_pref = 0;
				for (int j = 0; j < wall[i].size() -1; j++)
				{
					sum_pref += wall[i][j];
					sum_quant[sum_pref]++;
				}
			}
			int max = -1;
			for (auto it = sum_quant.begin(); it != sum_quant.end(); it++)
			{
				if(it->second > max)
					max = it->second;
			}
			return wall.size() - max;
		} else {
			return wall.size();
		}
		
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<int>> wall{{1,1}, {2}, {1,1}};
	ans.leastBricks(wall);
}