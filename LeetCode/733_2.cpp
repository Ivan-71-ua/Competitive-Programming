#include <bits/stdc++.h>


class Solution {
public:
	void changeColor(std::vector<std::vector<int>>& image, int x, int y, int color, int original)
	{
		if(image[x][y]==original)
		{
				image[x][y] = color;

				if ((x + 1) < image.size() && image[x + 1][y] == original)
					changeColor(image, x + 1, y, color, original);
				if ((y + 1) < image[0].size() && image[x][y + 1] == original)
					changeColor(image, x, y + 1, color, original);
				if ((x - 1) >= 0 && image[x - 1][y] == original)
					changeColor(image, x - 1, y, color, original);
				if ((y - 1) >= 0 && image[x][y - 1] == original)
					changeColor(image, x, y - 1, color, original);
		}
		return;
	}
	std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
		int original = image[sr][sc];
		if(color==original)
				return image;
		
		changeColor(image, sr, sc, color, original);
		return image;
	}
};


