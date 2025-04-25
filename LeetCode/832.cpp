#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
		for (int i = 0; i < image.size(); i++)
		{
			std::reverse(image[i].begin(), image[i].end());
		}
		
		for (int i = 0; i < image.size(); i++)
		{
			for (int j = 0; j < image.size(); j++)
			{
				//image[i][j] = (image[i][j] +1) % 2;
				if(image[i][j] == 1)
					image[i][j] = 0;
				else image[i][j] = 1;
			}
		}
		return image;
	}
};