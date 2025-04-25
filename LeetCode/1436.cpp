#include <bits/stdc++.h>

class Solution {
public:
   std::string destCity(std::vector<std::vector<std::string>>& paths) {
		std::unordered_map<std::string, std::string> road;
		int n = paths.size();
		std::string ans = "";
		for (int i = 0; i < n; i++)
		{
			road[paths[i][0]] = paths[i][1];
		}
		if(paths.size() ==1) {
			return paths[0][1];
		}
		auto it = road.begin();
		ans = it->second;
		while (road.count(ans))
		{
			ans = road[ans];
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<std::string>> paths{{"B", "C"}, {"D", "B"}, {"C", "A"}};
	std::cout << ans.destCity(paths);
}