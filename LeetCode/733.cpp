#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
		if(image[sr][sc] == color)
			return image;
		int n = image.size();
		int m = image[0].size();
		std::stack<std::pair<int, int>> way;
		way.push({sr, sc});
		while (!way.empty())
		{
			std::pair<int, int> tmp;
			std::tie(way.top()) = tmp;
			way.pop();
			if(tmp.first - 1 > -1 && image[tmp.first - 1][tmp.second] == image[tmp.first][tmp.second]) {
				way.push({tmp.first - 1, tmp.second});
			}
			if(tmp.first + 1 < n && image[tmp.first + 1][tmp.second] == image[tmp.first][tmp.second]) {
				way.push({tmp.first + 1, tmp.second});
			}
			if(tmp.second - 1 > -1 && image[tmp.first][tmp.second - 1] == image[tmp.first][tmp.second]) {
				way.push({tmp.first, tmp.second -1});
			}
			if(tmp.second + 1 < m && image[tmp.first][tmp.second + 1] == image[tmp.first][tmp.second]) {
				way.push({tmp.first, tmp.second + 1});
			}
			image[tmp.first][tmp.second] = color;
		}
		return image;
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<int>> arr{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
	ans.floodFill(arr, 1, 1, 2);
}