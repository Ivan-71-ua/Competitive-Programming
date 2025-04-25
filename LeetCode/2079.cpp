#include <bits/stdc++.h>


class Solution {
public:
	int wateringPlants(std::vector<int>& plants, int capacity) {
		int water = capacity;
		int res = 0;
		for (int i = 0; i < plants.size(); i++)
		{
			if(water >= plants[i]) {
				res++;
				water -= plants[i];
			} else {
				res += i + i + 1;
				water = capacity - plants[i];
			}
		}
		return res;
	}
};