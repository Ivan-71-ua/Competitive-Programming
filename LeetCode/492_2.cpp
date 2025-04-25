#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> constructRectangle(int area) 
	{
		int w=sqrt(area);
		int i;
		while(area%w!=0)
		{
				w--;
		}
		return {area/w, w};
	}
};