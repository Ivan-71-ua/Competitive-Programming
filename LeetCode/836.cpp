#include <bits/stdc++.h>


struct Rect
{
	int minX;
	int minY;
	int maxX;
	int maxY;
	Rect(std::vector<int> rec) {
		minX = rec[0];
		minY = rec[1];
		maxX = rec[2];
		maxY = rec[3];	
	}
};


class Solution {
	bool isRectangleOverlap(int min1, int max1, int min2, int max2) {
		return !(min1 >= max2 || min2 >= max1);
	}
public:
	bool isRectangleOverlap(Rect r1, Rect r2) {
		return isRectangleOverlap(r1.minX, r1.maxX, r2.minX, r2.maxX) && isRectangleOverlap(r1.minY, r1.maxY, r2.minY, r2.maxY);
	}
	bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
		return isRectangleOverlap(Rect(rec1), Rect(rec2));
	}
};