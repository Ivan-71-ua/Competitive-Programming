#include <bits/stdc++.h>


const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
   bool isPathCrossing(std::string path) {
		int x = 0, y = 0;
		std::unordered_map<std::string, bool> value;
		value["0#0#"] = true;
		for (int i = 0; i < path.size(); i++)
		{
			if(path[i] == 'N')
				y++;
			if(path[i] ==  'S')
				y--;
			if(path[i] == 'E')
				x++;
			if(path[i] == 'W')
				x--;
			std::string s;
			s += std::to_string(x);
			s += '#';
			s += std::to_string(y);
			s += '#';
			if(value.count(s)) {
				return true;
			}
			value[s] = true;
		}
		return false;
		}
};

int main() {
	Solution ans;
	ans.isPathCrossing("ENNNNNNNNNNNEEEEEEEEEESSSSSSSSSS");
}